package com.jni.jnitest;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    Button button;
    TextView tv;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        button = findViewById(R.id.button);
        tv = findViewById(R.id.tv);

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                JNITest jniTest = new JNITest();
                if (jniTest.isEquals("ssBCqpBssP")){
                    tv.setText("结果："+ new JNITest().getString());
                }else{
                    tv.setText("NULL POINTER");
                }

            }
        });

    }
}
