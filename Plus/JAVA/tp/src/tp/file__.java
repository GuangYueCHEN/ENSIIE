package tp;
import java.io.*;
public class file__ {
public static void main(String []arg) throws IOException{
	File ff =new File("/Users/pingguo/wtf/file_jave/ds");
	InputStream rd =new FileInputStream(ff); 
	int size =  rd.available();

    for(int i=0; i< size; i++){
      System.out.print((char)rd.read());
    }
      rd.close();
      System.out.print("\n");
      File f =new File("/Users/pingguo/wtf/file_jave/sd"); 
      byte bWrite [] = {11,21,3,40,5};
      OutputStream os = new FileOutputStream(f);
      for(int x=0; x < bWrite.length ; x++){
      os.write( bWrite[x] ); // writes the bytes
    }
    os.close();
      
    InputStream is = new FileInputStream(f);
    int size2 = is.available();
 
    for(int i=0; i< size2; i++){
      System.out.print(is.read() + "  ");
    }
      is.close();
      System.out.print("\n*******\n");
      FileOutputStream fop = new FileOutputStream(f);
      // 构建FileOutputStream对象,文件不存在会自动新建
      
      OutputStreamWriter writer = new OutputStreamWriter(fop, "UTF-8");
      // 构建OutputStreamWriter对象,参数可以指定编码,默认为操作系统默认编码,windows上是gbk
      
      writer.append("中文输入");
      // 写入到缓冲区
      
      writer.append("\n");
      //换行
      
      writer.append("English\n");
      // 刷新缓存冲,写入到文件,如果下面已经没有写入的内容了,直接close也会写入
      
      writer.close();
      //关闭写入流,同时会把缓冲区内容写入文件,所以上面的注释掉
      
      fop.close();
      // 关闭输出流,释放系统资源
   
      FileInputStream fip = new FileInputStream(f);
      // 构建FileInputStream对象
      FileInputStream fip2 = new FileInputStream(ff);
      InputStreamReader reader = new InputStreamReader(fip);
      // 构建InputStreamReader对象,编码与写入相同
      InputStreamReader reader2 = new InputStreamReader(fip2);
      StringBuffer sb = new StringBuffer();
      StringBuffer sb2 = new StringBuffer();
      //为什么要构建StringBuffer类
      while (reader.ready()) {
        sb.append((char) reader.read());
        // 转成char加到StringBuffer对象中
      }
      while (reader2.ready()) {
          sb.append((char) reader2.read());
          // 转成char加到StringBuffer对象中
        }
      System.out.println(sb.toString());
      System.out.println(sb2.toString());
      reader.close();
      // 关闭读取流
      
      fip.close();
      reader2.close();
      // 关闭读取流
      
      fip2.close();
      
      
      File file = new File("/Users/pingguo/wtf/file_jave/Hello1.txt");
      // 创建文件
      file.createNewFile();
      // creates a FileWriter Object
      FileWriter writer2 = new FileWriter(file); 
      // 向文件写入内容
      writer2.write("This\nis\nan\nexample\n"); 
      writer2.flush();
      writer2.close();
      // 创建 FileReader 对象
      FileReader fr = new FileReader(file); 
      char [] a = new char[50];
      fr.read(a); // 读取数组中的内容
      for(char c : a)
          System.out.print(c); // 一个一个打印字符
      fr.close();
      
      
      
      
}
}
