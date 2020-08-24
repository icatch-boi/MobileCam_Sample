package icatchtek.com.streamingalone.ui.sdkrenderoverusb;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.view.View;
import android.widget.Button;

import icatchtek.com.streamingalone.R;
import icatchtek.com.streamingalone.ui.sdkrenderoverusb.usb.NotificationHandler;
import icatchtek.com.streamingalone.ui.sdkrenderoverusb.usb.USBHost_Feature;

public class UsbPermissionActivity extends Activity
{
    public static int __VENDOR_ID__ = USBHost_Feature.USB_VENDOR_ID;
    public static int __PRODUCT_ID  = USBHost_Feature.USB_PRODUCT_ID;

    private USBHost_Feature feature;

    //----------------------------------------------------------------------------------------------
    /* Override activity's lifecycle methods. */
    //----------------------------------------------------------------------------------------------
    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_usb_premission);

        /* create feature, set device, register */
        Handler handler = new NotificationHandler(this);
        this.feature = new USBHost_Feature(this, handler);
        this.feature.setUsbDevice(this, __VENDOR_ID__,  __PRODUCT_ID);
        this.feature.register();

        /* ------------------------------------*/
        /* The usb related operations */
        /* ------------------------------------*/
        Button request_permission = findViewById(R.id.request_permission);
        request_permission.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                feature.requestPermission();
            }
        });

        Button preview_activity = findViewById(R.id.PreviewActivity);
        preview_activity.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent();
                intent.setClass(UsbPermissionActivity.this, SDKRenderActivity2.class);
                startActivity(intent);
            }
        });
    }

    protected void onDestroy()
    {
        super.onDestroy();

        if (this.feature != null) {
            this.feature.unregister();
        }
    }
}
