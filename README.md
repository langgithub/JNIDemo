# JNIDemo
1. ndk编译 cmake编译
2. 签名校验
3. so反调试
4. native动态加载

### cmake编译
暂且没研究

### jni ndk编译
1. /Users/yuanlang/Library/Android/sdk/ndk-bundle/ndk-build
2. build.gradle as编译过程,指定so名称和路径
        ndk{
            moduleName "JniLib"
            // abiFilters "armeabi", "armeabi-v7a", "x86" //输出指定的三种abi体系下的so库
        }
        sourceSets.main{
            //屏蔽srcDirs
            jni.srcDirs = []
            //指定libs
            jniLibs.srcDir "src/main/libs"
        }


### 签名校验
1. java端签名校验
    判断packageInfo.signatures 中的值是否等于 app_sign
2. so端签名校验
    反射获取getSignature 中的值是否等于 app_sign

### so反调试
1. 获取当前pid
2. 读取 /proc/%d/status 当前文件
3. 读取 第6行数据TracerPid 如果 TracerPid > 0 代表处于被调试状态

### native动态加载
1. cd app/src/main/java
2. javah com.jni.jnitest.JNITest
3. 移动 com_jni_jnitest_JNITest.h 到jni文件下

