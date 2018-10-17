package tp;
import java.util.regex.*;
public class ZhengZeBiaoDa {
	 //private static final String REGEX = "\\bcat\\b";
	    final static String INPUT ="cat gcat cat cattie catp";
	public static void main( String args[] ){
		 
	      // 按指定模式在字符串查找
	      String line = "This order was placed for QT3000! OK?";
	      String pattern = "(.*)(\\d+)(.*)";
	 
	      // 创建 Pattern 对象
	      Pattern r = Pattern.compile(pattern);
	 
	      // 现在创建 matcher 对象
	      Matcher m = r.matcher(line);
	      if (m.find( )) {
	         System.out.println("Found value: " + m.group(0) );
	         System.out.println("Found value: " + m.group(1) );
	         System.out.println("Found value: " + m.group(2) );
	         System.out.println("Found value: " + m.group(3) ); 
	      } else {
	         System.out.println("NO MATCH");
	      }
	   
	
	
	                                    
	     final String REGEX = "\\bcat\\b";
	
	       Pattern p = Pattern.compile(REGEX);
	       Matcher o = p.matcher(INPUT); // 获取 matcher 对象
	       int count = 0;
	 
	       while(o.find()) {
	         count++;
	         System.out.println("Match number "+count);
	         System.out.println("start(): "+o.start());
	         System.out.println("end(): "+o.end());
	      }
	
	       System.out.println("lookingAt(): "+o.lookingAt());
	       System.out.println("matches(): "+o.matches());
	
	
	}
	
}
