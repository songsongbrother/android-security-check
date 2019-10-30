package com.song.check;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button anti_debug = ((Button) findViewById(R.id.btn_anti_debug));
        Button anti_hook = ((Button) findViewById(R.id.btn_anti_hook));
        Button anti_dk = ((Button) findViewById(R.id.btn_anti_dk));
        Button anti_emulator = ((Button) findViewById(R.id.btn_anti_emulator));

        anti_debug.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(getApplicationContext(), AntiDebugActivity.class));
            }
        });
        anti_hook.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(getApplicationContext(), AntiHookActivity.class));
            }
        });
        anti_dk.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(getApplicationContext(), AntiDKActivity.class));
            }
        });
        anti_emulator.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(getApplicationContext(), AntiEmulatorActivity.class));
            }
        });
    }

}
