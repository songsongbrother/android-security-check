//
// Created by 陈颂颂 on 2019/8/27.
//

#include <jni.h>

#ifndef ANDROID_SECURITY_CHECK_ANTI_DEBUG_H
#define ANDROID_SECURITY_CHECK_ANTI_DEBUG_H

jstring stringFromTime(JNIEnv *env);

jstring stringFromFile(JNIEnv *env);

jstring stringFromTrick(JNIEnv *env);

jstring stringFromVm(JNIEnv *env);

jstring stringFromPtrace(JNIEnv *env);

jstring stringFromBkpt(JNIEnv *env);

jstring stringFromSignal(JNIEnv *env);

jstring stringFromFork(JNIEnv *env);

#endif //ANDROID_SECURITY_CHECK_ANTI_DEBUG_H
