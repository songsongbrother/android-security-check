#include <jni.h>
#include <string>

#include "include/anti-debug.h"

/**
 * 对外接口类
 */

extern "C" JNIEXPORT jstring JNICALL
Java_com_song_check_AntiDebugActivity_stringFromTime(JNIEnv *env, jobject /* this */) {
    return stringFromTime(env);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_song_check_AntiDebugActivity_stringFromFile(JNIEnv *env, jobject /* this */) {
    return stringFromFile(env);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_song_check_AntiDebugActivity_stringFromTrick(JNIEnv *env, jobject /* this */) {
    return stringFromTrick(env);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_song_check_AntiDebugActivity_stringFromVm(JNIEnv *env, jobject /* this */) {
    return stringFromVm(env);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_song_check_AntiDebugActivity_stringFromPtrace(JNIEnv *env, jobject /* this */) {
    return stringFromPtrace(env);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_song_check_AntiDebugActivity_stringFromBkpt(JNIEnv *env, jobject /* this */) {
    return stringFromBkpt(env);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_song_check_AntiDebugActivity_stringFromSignal(JNIEnv *env, jobject /* this */) {
    return stringFromSignal(env);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_song_check_AntiDebugActivity_stringFromFork(JNIEnv *env, jobject /* this */) {
    return stringFromFork(env);
}
