//
// Created by alexi on 4/3/2018.
//

#include "OARSname.h"
#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring

JNICALL
Java_com_q2i_q2iprov_MainActivity_stringz(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_q2i_q2iprov_DatahubCASA_DatahubCASA__(JNIEnv *env, jobject instance) {

    // TODO


    return env->NewStringUTF(returnValue);
}