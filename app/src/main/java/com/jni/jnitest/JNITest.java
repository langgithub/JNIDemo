package com.jni.jnitest;

/**
 * @author : zhangning
 * @time : 2018/3/26 12:24
 * @description :
 */

public class JNITest {

    static {
        System.loadLibrary("JniLib");
    }

    public native String getString();

    public native boolean isEquals(String str);


}
