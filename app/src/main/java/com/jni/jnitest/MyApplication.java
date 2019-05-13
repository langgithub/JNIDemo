package com.jni.jnitest;

import android.app.Application;
import android.content.Context;
import android.util.Log;

/**
 * Created by jiangwei1-g on 2016/5/27.
 */
public class MyApplication extends Application {

    private static Context mContext;

    @Override
    public void onCreate() {
        super.onCreate();
        mContext = this.getApplicationContext();

        boolean isOwnApp = Utils.isOwnApp();
        Log.i("jw", "isownapp:"+isOwnApp);
        if(isOwnApp){
            Log.i("jw", "is not own app...exit app");
            android.os.Process.killProcess(android.os.Process.myPid());
        }

    }

    public static Context getMyContext(){
        return mContext;
    }

}
