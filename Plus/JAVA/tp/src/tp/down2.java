package tp;


import java.io.*;
import java.net.*;

public class down2 {
public static void main() throws IOException{
	
final	String  destUrl ="http://javaweb.cc/网络编程001.zip";
	URL url = new URL(destUrl);
	HttpURLConnection httpUrl=(HttpURLConnection) url.openConnection();
     httpUrl.connect();
     BufferedInputStream bis= new BufferedInputStream(httpUrl.getInputStream());
     System.getProperties().put("proxySet", "true");
     System.getProperties().put("proxyHost", "10.154.134.110");
     System.getProperties().put("proxyHost", "8080");
     






}
}
