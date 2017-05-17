package com.zhangyp.higo.gradle_experimental_ndk;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView tv = (TextView) findViewById(R.id.tv);


        System.loadLibrary("testjni");

        MyNdk ndk = new MyNdk();
       // tv.setText(ndk.getString());

       /// tv.setText(ndk.getParams());
    }
}
