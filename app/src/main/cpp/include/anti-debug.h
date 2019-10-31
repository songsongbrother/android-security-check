//
// Created by 陈颂颂 on 2019/8/27.
//

#include <jni.h>

#ifndef ANDROID_SECURITY_CHECK_ANTI_DEBUG_H
#define ANDROID_SECURITY_CHECK_ANTI_DEBUG_H

jstring timeCheck(JNIEnv *env);

jstring tracerIdCheck(JNIEnv *env);

jstring vmCheck(JNIEnv *env);

jstring ptraceCheck(JNIEnv *env);

jstring checkBreakPoint(JNIEnv *env);

jstring stringFromSignal(JNIEnv *env);

jstring daemonCheck(JNIEnv *env);

#endif //ANDROID_SECURITY_CHECK_ANTI_DEBUG_H
