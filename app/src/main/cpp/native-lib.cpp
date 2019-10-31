#include <jni.h>
#include <string>

#include "include/anti-debug.h"

/**
 * 对外接口类
 */

extern "C" JNIEXPORT jstring JNICALL
Java_com_song_check_AntiDebugActivity_stringFromTime(JNIEnv *env, jobject /* this */) {
    return timeCheck(env);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_song_check_AntiDebugActivity_stringFromFile(JNIEnv *env, jobject /* this */) {
    return tracerIdCheck(env);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_song_check_AntiDebugActivity_stringFromVm(JNIEnv *env, jobject /* this */) {
    return vmCheck(env);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_song_check_AntiDebugActivity_stringFromPtrace(JNIEnv *env, jobject /* this */) {
    return ptraceCheck(env);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_song_check_AntiDebugActivity_stringFromBkpt(JNIEnv *env, jobject /* this */) {
    return checkBreakPoint(env);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_song_check_AntiDebugActivity_stringFromSignal(JNIEnv *env, jobject /* this */) {
    return stringFromSignal(env);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_song_check_AntiDebugActivity_stringFromFork(JNIEnv *env, jobject /* this */) {
    return daemonCheck(env);
}
