package tp;

import java.net.*;
import java.io.*;


public class down3 {

	public static void main() throws IOException {
		int bytesum = 0;  
        int byteread = 0;  
        
          URL url = new URL("https://www.google.fr/imgres?imgurl=http%3A%2F%2Fwww.tupian.de%2Fbirne.jpg&imgrefurl=http%3A%2F%2Fwww.tupian.de%2F&docid=YUdV4H0lz06HzM&tbnid=spe9ayCKi3mlDM%3A&vet=10ahUKEwiCxry35bfXAhWsL8AKHYGjDz8QMwglKAAwAA..i&w=701&h=621&bih=689&biw=1239&q=tupian&ved=0ahUKEwiCxry35bfXAhWsL8AKHYGjDz8QMwglKAAwAA&iact=mrc&uact=8");                 
            URLConnection conn = url.openConnection();  
            InputStream inStream = conn.getInputStream();                    
            File fileD =new File("/users/pingguo/wtf/dv");      
          //如果文件夹不存在则创建      
          if  (!fileD .exists()  && !fileD .isDirectory())        
          {         
              System.out.println("正在新建目录");    
              fileD .mkdirs();;      
          } else     
          {    
              System.out.println("目录存在");    
          }    
            File file=new File("/users/pingguo/wtf/dv/123.avi");   
            if(!file.exists())      
            {      
                try {      
                    file.createNewFile();      
                } catch (IOException e) {      
                    // TODO Auto-generated catch block      
                    e.printStackTrace();      
                }      
            }      
            FileOutputStream fs = new FileOutputStream("/users/pingguo/wtf/dv/123.avi");  
            byte[] buffer = new byte[1204];                   
            while ((byteread = inStream.read(buffer)) != -1) {  
                bytesum += byteread;  
                System.out.println(bytesum);  
                fs.write(buffer, 0, byteread);  
            }  
            System.out.println("downloaded ok");  
        fs.close();
	}
}
