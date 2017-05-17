#include <jni.h>

#include <stdio.h>
#include <assert.h>



JNIEXPORT jstring JNICALL
Java_com_zhangyp_higo_gradle_1experimental_1ndk_MyNdk_getString(JNIEnv *env, jobject instance) {

    // TODO 我们随便返回字符串，验证


    int a = 10;

    return (*env)->NewStringUTF(env, "Hello zzyyppqq !!!");
}

JNIEXPORT jfloat JNICALL
Java_com_zhangyp_higo_gradle_1experimental_1ndk_MyNdk_getFloat(JNIEnv *env, jobject instance) {

    // TODO

}
