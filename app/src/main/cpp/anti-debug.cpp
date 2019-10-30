//
// Created by 陈颂颂 on 2019/8/27.
//

#include <jni.h>
#include <string>
#include <sys/ptrace.h>
#include<iostream>
#include<sstream>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <fcntl.h>
#include "android/log.h"
#include <errno.h>
#include <dlfcn.h>
#include <time.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <sys/mman.h>
#include <stdbool.h>

#include "include/anti-debug.h"
#include "include/song-tools.h"
#include "include/song-log.h"
#include "include/gt-mob-daemon.h"

using std::string;

/**
 * 时间检测
 * @param env
 * @return
 */
jstring timeCheck(JNIEnv *env) {
    long start, end;
    start = clock();
    string hello = "Hello from time";
    end = clock();
    if (end - start > 10000) {
        hello = "Debug from time";
    }
    return env->NewStringUTF(hello.c_str());
}

/**
 * tracerId 检测
 * @param env
 * @return
 */
jstring tracerIdCheck(JNIEnv *env) {

    string hello;
    int pid = getpid();
    char path[32];
    sprintf(path, "/proc/%d/status", pid);
    LOGI("status path:%s", path);

    int fd;
    char *buf = new char[512];
    fd = open(path, O_RDONLY | O_CLOEXEC);
    read(fd, buf, 512);

    char *idStart;
    const char *tra = "TracerPid";
    idStart = strstr(buf, tra);
    char *idEnd;
    idEnd = strstr(idStart, "\n");
    unsigned long length = idEnd - idStart;
    char line[64];
    strncpy(line, idStart, length);
    char tracerPid[16];
    sscanf(line, "TracerPid:%*[^0-9]%64[0-9]", tracerPid);
    LOGI("line: %s tracerPid: %s", line, tracerPid);

    if (strcmp(tracerPid, "0") != 0) {
        hello = "Debug from file";
    } else {
        hello = "Hello from file";
    }

    close(fd);
    free(buf);

    return env->NewStringUTF(hello.c_str());
}

jstring stringFromTrick(JNIEnv *env) {
    string hello = "Hello from trick";
    return env->NewStringUTF(hello.c_str());
}

/**
 * 虚拟机标识检测
 * @param env
 * @return
 */
jstring vmCheck(JNIEnv *env) {

    string hello;

    // android.os.Debug.isDebuggerConnected()
    jclass debug_class = env->FindClass("android/os/Debug");
    jmethodID isDebug_mId = env->GetStaticMethodID(debug_class, "isDebuggerConnected", "()Z");
    jboolean isDebug = env->CallStaticBooleanMethod(debug_class, isDebug_mId);
    if (isDebug) {
        hello = "vm environment";
    } else {
        hello = "not vm environment";
    }

    return env->NewStringUTF(hello.c_str());
}

jstring stringFromPtrace(JNIEnv *env) {
    int check = ptrace(PTRACE_TRACEME, 0, 0, 0);
    LOGI("ret of ptrace : %d", check);
    string hello = "Hello from ptrace";
    if (check != 0) {
        hello = "Debug from ptrace";
    }
    return env->NewStringUTF(hello.c_str());
}

jstring stringFromBkpt(JNIEnv *env) {
    string hello = "Hello from bkpt";
    if (checkBreakPoint())
        hello = "Debug from bkpt";
    return env->NewStringUTF(hello.c_str());
}

char dynamic_ccode[] = {0x1f, 0xb4, //push {r0-r4}
                        0x01, 0xde, //breakpoint
                        0x1f, 0xbc, //pop {r0-r4}
                        0xf7, 0x46};//mov pc,lr

char *g_addr = 0;

void my_sigtrap(int sig) {
    LOGI("my_sigtrap\n");

    char change_bkp[] = {0x00, 0x46}; //mov r0,r0
    memcpy(g_addr + 2, change_bkp, 2);
    __builtin___clear_cache(g_addr, (g_addr + 8)); // need to clear cache
    LOGI("chang bpk to nop\n");

}

//void anti4() {//SIGTRAP
//
//    int ret, size;
//    char *addr, *tmpaddr;
//
//    signal(SIGTRAP, my_sigtrap);
//
//    addr = (char *) malloc(PAGE_SIZE * 2);
//
//    memset(addr, 0, PAGE_SIZE * 2);
//    g_addr = (char *) (((long) addr + PAGE_SIZE - 1) & ~(PAGE_SIZE - 1));
//
//    LOGI("addr: %p ,g_addr : %p\n", addr, g_addr);
//
//    ret = mprotect(g_addr, PAGE_SIZE, PROT_READ | PROT_WRITE | PROT_EXEC);
//    if (ret != 0) {
//        LOGI("mprotect error\n");
//        return;
//    }
//
//    size = 8;
//    memcpy(g_addr, dynamic_ccode, size);
//
//    __builtin___clear_cache(g_addr, (g_addr + size)); // need to clear cache
//    LOGI("start stub\n");
//
//    __asm__("push {r5}\n"
//            "push {r0-r4,lr}\n"
//            "mov r0,pc\n"  //此时pc指向后两条指令
//            "add r0,r0,#6\n"//cjh:这里的add是add.w，所以会占32位，因此需要+6才对。 原文：+4 是的lr 地址为 pop{r0-r5}
//            "mov lr,r0\n"
//            "mov pc,%0\n"
//            "pop {r0-r5}\n"
//            "mov lr,r5\n" //恢复lr
//            "pop {r5}\n"
//    :
//    :"r"(g_addr)
//    :);
//
//    LOGI("hi, i'm here\n");
//    free(addr);
//    LOGI("hi, i'm here2\n");
//
//}

jstring stringFromSignal(JNIEnv *env) {
//    anti4();
    string hello = "Hello from signal";
    return env->NewStringUTF(hello.c_str());
}

/**
 * 守护进程测试
 * @param env
 * @return
 */
jstring daemonCheck(JNIEnv *env) {
    startDaemon();
    return env->NewStringUTF("Daemon started.");
}
