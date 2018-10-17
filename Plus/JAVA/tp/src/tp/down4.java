package tp;

import java.io.ByteArrayOutputStream;  
import java.io.File;  
import java.io.FileOutputStream;  
import java.io.IOException;  
import java.io.InputStream;  
import java.net.HttpURLConnection;  
import java.net.URL;  
  
  
public class down4 {  
    /** 
     *
     * @param urlStr 
     * @param fileName 
     * @param savePath 
     * @throws IOException 
     */  
    public static void downLoadFromUrl(String urlStr, String fileName,String savePath) throws IOException {  
        URL url = new URL(urlStr);  
        HttpURLConnection conn = (HttpURLConnection) url.openConnection();  
        // 设置超时间为3秒  
        conn.setConnectTimeout(3 * 1000);  
        // 防止屏蔽程序抓取而返回403错误  
        conn.setRequestProperty("User-Agent","Mozilla/4.0 (compatible; MSIE 5.0; Windows NT; DigExt)");  
          
        // 得到输入流  
        InputStream inputStream = conn.getInputStream();  
        // 获取自己数组  
        byte[] getData = readInputStream(inputStream);  
          
        // 文件保存位置  
        File saveDir = new File(savePath);  
        if (!saveDir.exists()) {  
            saveDir.mkdir();  
        }  
        File file = new File(saveDir + File.separator + fileName);  
        FileOutputStream fos = new FileOutputStream(file);  
        fos.write(getData);  
        if (fos != null) {  
            fos.close();  
        }  
        if (inputStream != null) {  
            inputStream.close();  
        }  
          
        System.out.println("info:" + url + " download success");  
          
    }  
      
    /** 
     * 从输入流中获取字节数组 
     * @param inputStream 
     * @return 
     * @throws IOException 
     */  
    public static byte[] readInputStream(InputStream inputStream)throws IOException {  
       ByteArrayOutputStream swapStream = new ByteArrayOutputStream();  
        byte[] buff = new byte[1024];  
        int len = 0;  
        while ((len = inputStream.read(buff, 0, 100)) > 0) {  
        	swapStream.write(buff, 0, len);  
        }  
        byte[] body = swapStream.toByteArray();
        swapStream.close();  
        return body;  
    }  
      
    public static void main(String[] args) {  
        try {  
            downLoadFromUrl("http://www.bobopop.com/wp-content/uploads/2017/03/2658003-tian-mei-nv-sheng-zhong-duan-fa-fa-xing-tu-pian.jpeg","tp.jpg", "/users/pingguo/wtf/images");  
        } catch (Exception e) {  
            e.printStackTrace();  
        }  
    }  
}  