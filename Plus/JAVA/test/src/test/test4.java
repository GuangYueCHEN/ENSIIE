package test;

public class test4 {
	
	public int reverse(int x) {
		int res=0,y;
		while(x!=0) {
			y=x%10;
			x=x/10;
			res=res*10+y;
			
		}
		
		
		
		
		
		return res;
	      
			
	        
	    }
}
