package com.song.check;

import android.content.Context;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class AntiDebugActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_anti_debug);

        Button time_button = (Button)findViewById(R.id.time_button);
        Button file_button = (Button)findViewById(R.id.file_button);
        Button trick_button = (Button)findViewById(R.id.trick_button);
        Button vm_button = (Button)findViewById(R.id.vm_button);
        Button ptrace_button = (Button)findViewById(R.id.ptrace_button);
        Button bkpt_button = (Button)findViewById(R.id.bkpt_button);
        Button fork_button = (Button)findViewById(R.id.fork_button);
        Button signal_button = (Button)findViewById(R.id.signal_button);

        time_button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Context context = getApplicationContext();
                Toast.makeText(context, stringFromTime(),Toast.LENGTH_LONG).show();
            }
        });

        file_button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Context context = getApplicationContext();
                Toast.makeText(context, stringFromFile(),Toast.LENGTH_LONG).show();
            }
        });

        trick_button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Context context = getApplicationContext();
                Toast.makeText(context, stringFromTrick(),Toast.LENGTH_LONG).show();
            }
        });

        vm_button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Context context = getApplicationContext();
                if(android.os.Debug.isDebuggerConnected()){
                    Toast.makeText(context, "Debug from vm",Toast.LENGTH_LONG).show();
                }
                else{
                    Toast.makeText(context, "Hello from vm",Toast.LENGTH_LONG).show();
                }
            }
        });

        ptrace_button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Context context = getApplicationContext();
                Toast.makeText(context, stringFromPtrace(),Toast.LENGTH_LONG).show();
            }
        });

        bkpt_button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Context context = getApplicationContext();
                Toast.makeText(context, stringFromBkpt(),Toast.LENGTH_LONG).show();
            }
        });

        fork_button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Context context = getApplicationContext();
                Toast.makeText(context, stringFromFork(),Toast.LENGTH_LONG).show();
            }
        });

        signal_button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Context context = getApplicationContext();
                Toast.makeText(context, stringFromSignal(),Toast.LENGTH_LONG).show();
            }
        });
    }

    public native String stringFromTime();
    public native String stringFromFile();
    public native String stringFromTrick();
    public native String stringFromVm();
    public native String stringFromPtrace();
    public native String stringFromBkpt();
    public native String stringFromFork();
    public native String stringFromSignal();
}
