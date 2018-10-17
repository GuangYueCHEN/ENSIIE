package classs;

	interface Animall {
		   public void eat();
		   public void travel();
		}
public class implements_jiekou implements Animall{
	
	
		 
		   public void eat(){
		      System.out.println("Mammal eats");
		   }
		 
		   public void travel(){
		      System.out.println("Mammal travels");
		   } 
		 
		   public int noOfLegs(){
		      return 0;
		   }
	
	 public  static void main(String args[]){
		 implements_jiekou m = new implements_jiekou();
		      m.eat();
		      m.travel();
		   }
		
}
