package tp;

public class Array_ {
public static void main(String []arg) {
	char[] a = new char[10];
	double[] b = {1.2,1.3,1.4,1.5};
	System.out.println("foreach******");
	for(double x : b) {
		System.out.println(x);
		
	}
	String s = "qwertasd";
	System.out.println("tochar******");
	a=s.toCharArray();
	System.out.println(a);
	
}
}
