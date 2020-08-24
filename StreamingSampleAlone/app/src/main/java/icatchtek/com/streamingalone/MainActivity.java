package icatchtek.com.streamingalone;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.os.Environment;
import android.view.View;
import android.widget.Button;

import com.icatchtek.pancam.customer.ICatchPancamLog;
import com.icatchtek.pancam.customer.type.ICatchGLLogLevel;
import com.icatchtek.pancam.customer.type.ICatchGLLogType;

import icatchtek.com.streamingalone.ui.sdkrender1.SDKRenderActivity1;
import icatchtek.com.streamingalone.ui.sdkrenderoverusb.UsbPermissionActivity;
import icatchtek.com.streamingalone.ui.apprender.AppRenderActivity1;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button app_render = findViewById(R.id.app_render);
        app_render.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent();
                intent.setClass(MainActivity.this, AppRenderActivity1.class);
                startActivity(intent);
            }
        });

        Button sdk_render = findViewById(R.id.sdk_render);
        sdk_render.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent();
                intent.setClass(MainActivity.this, SDKRenderActivity1.class);
                startActivity(intent);
            }
        });

        Button app_render_over_usb = findViewById(R.id.sdk_render_over_usb);
        app_render_over_usb.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent();
                intent.setClass(MainActivity.this, UsbPermissionActivity.class);
                startActivity(intent);
            }
        });

        initSDKLogger1();
    }

    private void initSDKLogger1()
    {
        String pancamSDKPath = Environment.getExternalStorageDirectory().getPath();

        ICatchPancamLog.getInstance().setDebugMode(true);
        ICatchPancamLog.getInstance().setFileLogPath(pancamSDKPath);
        ICatchPancamLog.getInstance().setFileLogOutput(true);
        ICatchPancamLog.getInstance().setSystemLogOutput(true);

        ICatchPancamLog.getInstance().setLog(ICatchGLLogType.ICH_GL_LOG_TYPE_COMMON, true);
        ICatchPancamLog.getInstance().setLogLevel(ICatchGLLogType.ICH_GL_LOG_TYPE_COMMON, ICatchGLLogLevel.ICH_GL_LOG_LEVEL_INFO);

        ICatchPancamLog.getInstance().setLog(ICatchGLLogType.ICH_GL_LOG_TYPE_OPENGL, true);
        ICatchPancamLog.getInstance().setLogLevel(ICatchGLLogType.ICH_GL_LOG_TYPE_OPENGL, ICatchGLLogLevel.ICH_GL_LOG_LEVEL_INFO);

        ICatchPancamLog.getInstance().setLog(ICatchGLLogType.ICH_GL_LOG_TYPE_DEVELOP, true);
        ICatchPancamLog.getInstance().setLogLevel(ICatchGLLogType.ICH_GL_LOG_TYPE_DEVELOP, ICatchGLLogLevel.ICH_GL_LOG_LEVEL_INFO);

        ICatchPancamLog.getInstance().setLog(ICatchGLLogType.ICH_GL_LOG_TYPE_STREAM, true);
        ICatchPancamLog.getInstance().setLogLevel(ICatchGLLogType.ICH_GL_LOG_TYPE_STREAM, ICatchGLLogLevel.ICH_GL_LOG_LEVEL_INFO);
    }
}
