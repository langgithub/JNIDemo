package com.jni.jnitest;

import android.content.Context;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.Signature;
import android.util.Log;

/**
 * Created by jiangwei1-g on 2016/5/27.
 */
public final class Utils {

    private static final String APP_SIGN = "3082030d308201f5a00302010202044054662e300d06092a864886f70d01010b05003037310b30090603550406130255533110300e060355040a1307416e64726f6964311630140603550403130d416e64726f6964204465627567301e170d3136303432303038323733395a170d3436303431333038323733395a3037310b30090603550406130255533110300e060355040a1307416e64726f6964311630140603550403130d416e64726f696420446562756730820122300d06092a864886f70d01010105000382010f003082010a028201010097682c11f190cf5a36feb8adf72a6d3a44e4cf5eb82527ebf396ffad13055ca59b6ba835d4b1a3e3ecc23d39bd1b5b19471e0d3024495b6d97c7a6aa57fe4156593f47af5444e973d19e6213489982e5943534db51315dddb7485f8ffc53e6e8b418394bace31cdcee2da397626cdbe30fe682db1a6b4a56718011f8aa391d0ff7917fc15007bb83ab40b98123cd89a28aeb4c6d2616e3cb91ec1e405cf05880172a3b7db7a3c7030238d2df21d9cfdefc24b6bc526c40b6f5755ce79fb5af778a0fec08e2399d98bcd7ae75c297ecf5e8759aa1839396a8031ac2a93631e4d02cbaabda78594a2d34384404690a1855189ea7dea10233805c2b829d71e5e30f0203010001a321301f301d0603551d0e041604147e68d92245a6b11d2aa611cb6e2f3331154523e8300d06092a864886f70d01010b05000382010100366e1b975c4235f195f7ccffe6c2618e2b9926792bc30fddd8b9c20bb4546684c48c88be8b2af3c8bb24815c6e83e94afdee35d173e7cfab204d0ea14a22df36e91a3fb5ffb7ababe978832039b0fadfcd0d7960b8fccc724ba7309b2c4c967bfb40fbd3f3265be23813d632cdca365782fcc61917229ce12c9e9c05ab61589aceff0de412e2cd985239859a1f1904841b730b5fe7a46905ba6c3dc0d927507baafde4398aecf0827ce0beb6f85a6e4c3f64fdc788220ff543d619ebeb2e15e1f9a6944ea04aee933271a02510679b1d2578edf3894832ed70b1039b0ddbaf0b1c7077c5fffd39daf0fb38a46fec384ee0b237855fe66a35cf46ebbf5cf919a0";

    public static String getSignature() {
        Context ctx = MyApplication.getMyContext();
        try {
            /** 通过包管理器获得指定包名包含签名的包信息 **/
            PackageInfo packageInfo = ctx.getPackageManager().getPackageInfo(ctx.getPackageName(), PackageManager.GET_SIGNATURES);
            /******* 通过返回的包信息获得签名数组 *******/
            Signature[] signatures = packageInfo.signatures;
            /******* 循环遍历签名数组拼接应用签名 *******/
            StringBuilder builder = new StringBuilder();
            for (Signature signature : signatures) {
                builder.append(signature.toCharsString());
            }
            /************** 得到应用签名 **************/
            return builder.toString();
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
        }
        return "";
    }

    public static boolean isOwnApp(){
        String signStr = getSignature();
        return APP_SIGN.equals(signStr);
    }

}
