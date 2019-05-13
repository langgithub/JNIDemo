/* DO NOT EDIT THIS FILE - it is machine generated */
#include "com_jni_jnitest_JNITest.h"
#include "JniLib.h"
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* Header for class com_jni_jnitest_JNITest */

/*
 * Class:     com_jni_jnitest_JNITest
 * Method:    getString
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_jni_jnitest_JNITest_getString
  (JNIEnv * env, jobject jobject){

  return (*env)->NewStringUTF(env,"成功调用JNI内容");

  }


/*
 * Class:     com_jni_jnitest_JNITest
 * Method:    isEquals
 * Signature: (Ljava/lang/String;)Z
 *
 *
 method1
 JNIEXPORT jboolean JNICALL Java_com_jni_jnitest_JNITest_isEquals
     (JNIEnv * env, jobject jobject, jstring jstring){


 }
 */


char key_src[] = {'z','y','t','y','r','T','R','A','*','B','n','i','q','C','P','p','V','s'};

int is_number(const char* src){
    if(src == NULL){
        return 0;
    }
    while(*src != '\0'){
        if(*src < 48 || *src > 57){
            return 0;
        }
        src++;
    }
    return 1;
}

char * get_encrypt_str(const char* src){
    LOGD("get_encrypt_str:%s", src);
    if(src == NULL){
        return NULL;
    }
    int len = strlen(src);
    len++;
    char *dest = (char*) malloc(len * sizeof(char));
    char *head = dest;
    const char *tmp = src;
    int i=0;
    int key_len = 18;
    for(;i<len;i++){
        int index = (*tmp) - 48;
        if(index == 0){
            index = 1;
        }
        *dest = key_src[key_len-index];
        tmp++;
        dest++;
    }
    dest++;
    *dest = '\0';
    return head;
}

JNIEXPORT jboolean JNICALL jiangwei
        (JNIEnv * env, jobject obj, jstring str)
{

    LOGD("JNIEnv1:%p", env);

    const char *strAry = (*env)->GetStringUTFChars(env, str, 0);
    LOGD("JNIEnv1:%s", strAry);
    int len = strlen(strAry);
    char* dest = (char*)malloc(len);
    strcpy(dest, strAry);

    int number = is_number(strAry);
    if(number == 0){
        LOGD("JNIEnv1 retrun");
        return 0;
    }

    char* encry_str = get_encrypt_str(strAry);
    const char* pas = "ssBCqpBssP";
    int result = strcmp(pas, encry_str);

    (*env)->ReleaseStringUTFChars(env, str, strAry);

    if(result == 0){
        return 1;
    }else{
        return 0;
    }

}

pthread_t t_id;

int getnumberfor_str(char* str){
    if(str == NULL){
        return -1;
    }
    char result[20];
    int count = 0;
    while(*str != '\0'){
        if(*str >= 48 && *str <= 57){
            result[count] = *str;
            count++;
        }
        str++;
    }
    int val = atoi(result);
    return val;
}

void *thread_fuction() {
    int pid = getpid();
    char file_name[20] = {'\0'};
    sprintf(file_name, "/proc/%d/status",pid);
    char linestr[256];
    int i=0, traceid;
    FILE *fp;
    while(1){
        i = 0;
        fp = fopen(file_name,"r");
        if(fp == NULL){
            break;
        }
        while(!feof(fp)){
            fgets(linestr, 256, fp);
            if(i == 5){
                traceid = getnumberfor_str(linestr);
                if(traceid > 0){
                    LOGD("I was be traced...trace pid:%d",traceid);
                    exit(0);
                    return 0;
                }
                break;
            }
            i++;
        }
        fclose(fp);
        sleep(5);
    }
    return 0;

}

void create_thread_check_traceid(){
    int err = pthread_create(&t_id,NULL, thread_fuction, NULL);
    if(err != 0 ) {
        LOGD("create thread fail: %s\n",strerror(err));
    }
}

const char *app_signature= "3082030d308201f5a00302010202044054662e300d06092a864886f70d01010b05003037310b30090603550406130255533110300e060355040a1307416e64726f6964311630140603550403130d416e64726f6964204465627567301e170d3136303432303038323733395a170d3436303431333038323733395a3037310b30090603550406130255533110300e060355040a1307416e64726f6964311630140603550403130d416e64726f696420446562756730820122300d06092a864886f70d01010105000382010f003082010a028201010097682c11f190cf5a36feb8adf72a6d3a44e4cf5eb82527ebf396ffad13055ca59b6ba835d4b1a3e3ecc23d39bd1b5b19471e0d3024495b6d97c7a6aa57fe4156593f47af5444e973d19e6213489982e5943534db51315dddb7485f8ffc53e6e8b418394bace31cdcee2da397626cdbe30fe682db1a6b4a56718011f8aa391d0ff7917fc15007bb83ab40b98123cd89a28aeb4c6d2616e3cb91ec1e405cf05880172a3b7db7a3c7030238d2df21d9cfdefc24b6bc526c40b6f5755ce79fb5af778a0fec08e2399d98bcd7ae75c297ecf5e8759aa1839396a8031ac2a93631e4d02cbaabda78594a2d34384404690a1855189ea7dea10233805c2b829d71e5e30f0203010001a321301f301d0603551d0e041604147e68d92245a6b11d2aa611cb6e2f3331154523e8300d06092a864886f70d01010b05000382010100366e1b975c4235f195f7ccffe6c2618e2b9926792bc30fddd8b9c20bb4546684c48c88be8b2af3c8bb24815c6e83e94afdee35d173e7cfab204d0ea14a22df36e91a3fb5ffb7ababe978832039b0fadfcd0d7960b8fccc724ba7309b2c4c967bfb40fbd3f3265be23813d632cdca365782fcc61917229ce12c9e9c05ab61589aceff0de412e2cd985239859a1f1904841b730b5fe7a46905ba6c3dc0d927507baafde4398aecf0827ce0beb6f85a6e4c3f64fdc788220ff543d619ebeb2e15e1f9a6944ea04aee933271a02510679b1d2578edf3894832ed70b1039b0ddbaf0b1c7077c5fffd39daf0fb38a46fec384ee0b237855fe66a35cf46ebbf5cf919a0";
int equal_sign(JNIEnv* env){

    //调用Java层的Utils中的获取签名的方法
    char* className = "com/jni/jnitest/Utils";
    jclass clazz = (*env)->FindClass(env, className);
    if (clazz == NULL) {
        LOGD("not find class '%s'", className);
        return 1;
    }

    LOGD("class name:%p", clazz);

    jmethodID method = (*env)->GetStaticMethodID(env, clazz, "getSignature", "()Ljava/lang/String;");
    if(method == NULL){
        LOGD("not find method %s", (jstring)method);
        return 1;
    }

    jstring obj = (jstring)(*env)->CallStaticObjectMethod(env, clazz,method);
    if(obj == NULL){
        LOGD("method invoke error:%p", obj);
        return 1;
    }

    const char *strAry = (*env)->GetStringUTFChars(env, obj, 0);
    int cmpval = strcmp(strAry, app_signature);
    if(cmpval == 0){
        LOGD("sign ok ！！！");
        return 1;
    }

    (*env)->ReleaseStringUTFChars(env, obj, strAry);

    return 0;

}

//定义目标类名称
static const char *className = "com/jni/jnitest/JNITest";

//定义方法隐射关系 动态注册
static JNINativeMethod methods[] = {
        {"isEquals", "(Ljava/lang/String;)Z", (void*)*jiangwei},
};

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved){
    LOGD("JNI on load...");

    //检测自己有没有被trace
    create_thread_check_traceid();

    //声明变量
    jint result = JNI_ERR;
    JNIEnv* env = NULL;
    jclass clazz;
    int methodsLenght;

    //获取JNI环境对象
    if ((*vm)->GetEnv(vm, (void**) &env, JNI_VERSION_1_4) != JNI_OK) {
        LOGD("ERROR: GetEnv failed\n");
        return JNI_ERR;
    }

    LOGD("JNIEnv:%p", env);
    LOGD("start equal signature...");
    int check_sign = equal_sign(env);
    LOGD("check_sign:%d", check_sign);
    if(check_sign != 0){
        exit(0);
    }

    //注册本地方法.Load 目标类
    clazz = (*env)->FindClass(env,className);
    if (clazz == NULL) {
        LOGD("Native registration unable to find class '%s'", className);
        return JNI_ERR;
    }

    //建立方法隐射关系
    //取得方法长度
    methodsLenght = sizeof(methods) / sizeof(methods[0]);
    if ((*env)->RegisterNatives(env,clazz, methods, methodsLenght) < 0) {
        LOGD("RegisterNatives failed for '%s'", className);
        return JNI_ERR;
    }

    result = JNI_VERSION_1_4;
    return result;
}

//onUnLoad方法，在JNI组件被释放时调用
void JNI_OnUnload(JavaVM* vm, void* reserved){
    LOGD("JNI unload...");
}