
public class exceptions_ {

	
	/*
	 * 捕获异常
	 * try
{
   // 程序代码
}catch(ExceptionName e1)
{
   //Catch 块
}

例子：

try{
         int a[] = new int[2];
         System.out.println("Access element three :" + a[3]);
      }catch(ArrayIndexOutOfBoundsException e){
         System.out.println("Exception thrown  :" + e);
      }
      System.out.println("Out of the block");
   }


多重捕获
try
{
  file = new FileInputStream(fileName);
  x = (byte) file.read();
}catch(IOException i)
{
  i.printStackTrace();
  return -1;
}catch(FileNotFoundException f) //Not valid!
{
  f.printStackTrace();
  return -1;
}finally{
  // 程序代码
}


















class MyException extends Exception{
}声明异常


	 */
}
