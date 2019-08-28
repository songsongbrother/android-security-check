#include <jni.h>
#include <string>

#include "include/anti-debug.h"

/**
 * 对外接口类
 */

extern "C" JNIEXPORT jstring JNICALL
Java_com_song_check_MainActivity_stringFromTime(JNIEnv *env, jobject /* this */) {
    return stringFromTime(env);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_song_check_MainActivity_stringFromFile(JNIEnv *env, jobject /* this */) {
    return stringFromFile(env);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_song_check_MainActivity_stringFromTrick(JNIEnv *env, jobject /* this */) {
    return stringFromTrick(env);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_song_check_MainActivity_stringFromVm(JNIEnv *env, jobject /* this */) {
    return stringFromVm(env);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_song_check_MainActivity_stringFromPtrace(JNIEnv *env, jobject /* this */) {
    return stringFromPtrace(env);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_song_check_MainActivity_stringFromBkpt(JNIEnv *env, jobject /* this */) {
    return stringFromBkpt(env);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_song_check_MainActivity_stringFromSignal(JNIEnv *env, jobject /* this */) {
    return stringFromSignal(env);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_song_check_MainActivity_stringFromFork(JNIEnv *env, jobject /* this */) {
    return stringFromFork(env);
}
