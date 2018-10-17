package classs;
class SuperClass {
  private int n;
  SuperClass(){
    System.out.println("SuperClass()");
  }
  SuperClass(int n) {
    System.out.println("SuperClass(int n)");
    this.n = n;
  }
}
class SubClass extends SuperClass{
  private int n;
  
  SubClass(){
    super(300);
    System.out.println("SubClass");
  }  
  
  public SubClass(int n){
    System.out.println("SubClass(int n):"+n);
    this.n = n;
  }
}
public class interface_jiekou_chouxiang {
/*
 *
继承  *  class 子类 extends 父类 （）{
     * super ()
     * }
 * 
 * 
 * 
 * 
 多重继承*public interface A{
 public void eat();
 }
 public interface b{
 public void show();
 }
 public class C implements A,B{
 }
        * 
        * 
 *
 * 
 * 
 * super 代表用父类的方法
 * this 代表用子类的方法
 * final 声明类不可继承
 * 
 * 
 * 
 * 无法继承构造函数
 * 

 */
	public static void main (String args[]){
	    SubClass sc = new SubClass();
	    SubClass sc2 = new SubClass(200); 
	  }//构造子类时会先调用父类的构造函数，若不声明自动调用无参数的

	
	/*
	
	
	*/
	
	
}
