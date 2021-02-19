//
// Created by 62527 on 2021/2/18.
//

#include <jni.h>
#include <string>
#include "people/people.h"

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_wyf_avdio_MainActivity_stringFromJNI(JNIEnv *env, jobject thiz) {
    // TODO: implement stringFromJNI()
    people mpeople;
    env->NewStringUTF(mpeople.getString().c_str());
}