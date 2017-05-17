//
//  ht_transcoder_jni.c
//  IJKMediaPlayer
//
//  Created by huiti123 on 2017/5/15.
//  Copyright © 2017年 bilibili. All rights reserved.
//


#include <jni.h>
#include <assert.h>
#include "test.h"

//com.zhangyp.higo.gradle_experimental_ndk

#define JNI_PACKAGE "com/zhangyp/higo/gradle_experimental_ndk"
#define JNI_CLASS   "com/zhangyp/higo/gradle_experimental_ndk/MyNdk"

static JavaVM *g_jvm;

typedef struct test_fields_t{
    jclass clazz;
    float   curper;
}test_fields_t;


static test_fields_t g_clazz;


/*
java
    public native void startTranscode( String params);
    public native int  getTranscodePercentage();

*/

void JNI_setParams(JNIEnv *env,jobject thiz,jobject params ,jobject folder){

    const char * json_params  = (*env)->GetStringUTFChars(env,params,NULL);
    if(json_params == NULL){
        goto LABEL_RETUREN;    // may throw execption
    }

    ALOGD("json_params = %s",json_params);


    const char * save_folder  = (*env)->GetStringUTFChars(env,folder,NULL);
    if(save_folder == NULL){
        goto LABEL_RETUREN;    // may throw execption
    }

       ALOGD("save_folder = %s",save_folder);


    ALOGD("start covert ");
    g_clazz.curper = 0;
LABEL_RETUREN:
    if(json_params != NULL){
       (*env)->ReleaseStringUTFChars(env,params,json_params);
    }

    if(save_folder != NULL){
       (*env)->ReleaseStringUTFChars(env,folder,save_folder);
    }
    ALOGD("after call JNI_startTranscode success ");
}

jfloat JNI_getParams(JNIEnv *env,jobject thiz){

  ALOGD("call JNI_getTranscodePercentage success ");
  jfloat ret = 0.f;
    return g_clazz.curper;
}

static JNINativeMethod g_methods[]={
    {"setParams","(Ljava/lang/String;Ljava/lang/String;)V",(void*)&JNI_setParams},
    {"getParams","()F",(void*)&JNI_getParams},
};


JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm,void *reserved){
    JNIEnv *env = NULL;

    g_jvm = vm;

    int ver = JNI_VERSION_1_4;
    if((*vm)->GetEnv(vm,(void**) &env,ver) != JNI_OK){
        return JNI_ERR;
    }

    assert(env != NULL);

    FIND_JAVA_CLASS(env,g_clazz.clazz,JNI_CLASS);
    (*env)->RegisterNatives(env,g_clazz.clazz,g_methods,NELEM(g_methods));
    return ver;
}

JNIEXPORT JNICALL void JNI_OnUnload(JavaVM *jvm,void *reserved){
    g_jvm = NULL;
}
