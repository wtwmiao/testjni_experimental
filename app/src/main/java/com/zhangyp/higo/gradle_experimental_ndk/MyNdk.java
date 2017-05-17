package com.zhangyp.higo.gradle_experimental_ndk;

/**
 * Created by zhangyipeng on 16/2/28.
 */
public class MyNdk {

    static {

    }

    public native String getString();

    public  native  float getFloat();

    public  native  String getParams();

    public  native  void  setParams(String str1,String str2);

}
