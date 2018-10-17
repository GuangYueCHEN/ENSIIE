package tp;
// Byte Double Float Integer Long Short
public class math_ {
public static void main(String []arg) {
	Integer a = 10;
	int b = 20;
	float c ;
	c=a.floatValue();
	Float d;
	d=a.floatValue();
	System.out.println("测试xxxValue");
	System.out.println(c);
	System.out.println(d);
	
	int n;
	int m,k;
	n=a.compareTo(2);
	m=a.compareTo(10);
	k=a.compareTo(b);
	System.out.println("测试compare");
	System.out.println(n);
	System.out.println(m);
	System.out.println(k);
	
	//String str = "444";
	System.out.println("String 与 int 转换");
	System.out.println(a.toString());
	/*m = Integer.parseInt("444");
	n = Integer.parseInt(str,2);
	System.out.println(m);
	System.out.println(n);
	*/
	double l,p,o;
	a= -10;
	p=1.2;
	m=Math.abs(a);
	l=Math.ceil(p);
	o=Math.rint(p);
	long f;
	f=Math.round(p);
	System.out.println("测试abs ceil floor rint（返回double）四舍五入round（返回long） ");
	System.out.println(m);	
	System.out.println(l);
	System.out.println(o);
	System.out.println(f);
	/*
	 * Math.max()
	 * double  Math.exp(double) 求e的次方 Math.E e的值
	 * double  Math.log(double)
	 * pow(double,double)
	 * sqrt(double)
	 * sin（double,double） cos tan asin acos atan atan2(极坐标)
	 * random()
	 * 基本都返回double
	*/
			
}
}
