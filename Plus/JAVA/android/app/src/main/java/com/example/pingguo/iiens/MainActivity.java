package com.example.pingguo.iiens;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import java.io.*;

public class MainActivity extends Activity {
    // 指定网页地址
    public String url = "http://blog.csdn.net/jasonzhou613/article/details/7905388";

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        manageException();// 处理抛出异常
        TextView tv = (TextView) findViewById(R.id.text);
        String myString = null;
        myString = posturl(url);
        // 设置屏幕显示
        Log.i("---网页代码---", "" + myString);
        String html = myString;
        Document doc = Jsoup.parse(html);
        tv.setText(doc.title());

    }

    /**
     * 获取参数指定的网页代码，将其返回给调用者，由调用者对其解析 返回String
     */
    public String posturl(String url) {
        InputStream is = null;
        String result = "";

        try {
            HttpClient httpclient = new DefaultHttpClient();
            HttpPost httppost = new HttpPost(url);
            HttpResponse response = httpclient.execute(httppost);
            HttpEntity entity = response.getEntity();
            is = entity.getContent();
        } catch (Exception e) {
            return "Fail to establish http connection!" + e.toString();
        }

        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(
                    is, "utf-8"));
            StringBuilder sb = new StringBuilder();
            String line = null;
            while ((line = reader.readLine()) != null) {
                sb.append(line + "\n");
            }
            is.close();

            result = sb.toString();
        } catch (Exception e) {
            return "Fail to convert net stream!";
        }

        return result;
    }

    public void manageException() {
        StrictMode.setThreadPolicy(new StrictMode.ThreadPolicy.Builder()
                .detectDiskReads().detectDiskWrites().detectNetwork() // or
                // .detectAll()
                // for
                // all
                // detectable
                // problems
                .penaltyLog().build());
        StrictMode.setVmPolicy(new StrictMode.VmPolicy.Builder()
                .detectLeakedSqlLiteObjects().penaltyLog().penaltyDeath()
                .build());
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.activity_main, menu);
        return true;
    }

}