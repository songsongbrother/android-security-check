//
// Created by 陈颂颂 on 2019/8/28.
//

#ifdef __cplusplus
extern "C" {
#endif

#ifndef ANDROID_SECURITY_CHECK_NATIVE_LIB_H
#define ANDROID_SECURITY_CHECK_NATIVE_LIB_H

#include <jni.h>

JNIEXPORT jstring JNICALL
Java_com_song_check_MainActivity_stringFromJNI(JNIEnv *env, jobject /* this */);

JNIEXPORT jstring JNICALL
Java_com_song_check_MainActivity_stringFromTime(JNIEnv *env, jobject /* this */);

JNIEXPORT jstring JNICALL
Java_com_song_check_MainActivity_stringFromFile(JNIEnv *env, jobject /* this */);

JNIEXPORT jstring JNICALL
Java_com_song_check_MainActivity_stringFromTrick(JNIEnv *env, jobject /* this */);

JNIEXPORT jstring JNICALL
Java_com_song_check_MainActivity_stringFromVm(JNIEnv *env, jobject /* this */);

JNIEXPORT jstring JNICALL
Java_com_song_check_MainActivity_stringFromPtrace(JNIEnv *env, jobject /* this */);

JNIEXPORT jstring JNICALL
Java_com_song_check_MainActivity_stringFromBkpt(JNIEnv *env, jobject /* this */);

JNIEXPORT jstring JNICALL
Java_com_song_check_MainActivity_stringFromSignal(JNIEnv *env, jobject /* this */);

JNIEXPORT jstring JNICALL
Java_com_song_check_MainActivity_stringFromFork(JNIEnv *env, jobject /* this */);

#endif //ANDROID_SECURITY_CHECK_NATIVE_LIB_H

#ifdef __cplusplus
}
#endif
