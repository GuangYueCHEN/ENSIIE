package test;

public class test2 {
	public class ListNode {
		     int val;
		      ListNode next;
		      ListNode(int x) { val = x; }
		  }
	
    @SuppressWarnings("unused")
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode l3 = new ListNode(0);
        ListNode sum = new ListNode(0);
        ListNode res = l3;
     int su;
        int sign=0;
        while(l1!=null){
            while(l2!=null) {
                if(sign==0)
                    su=l1.val+l2.val;
                else 
                    su=l1.val+l2.val+1;
                
            	   if(su>=10) {
            		   
            			   sum=new ListNode(su-10);
            		   l3.next=sum;
            		
            		   l3=l3.next;
            		   sign=1;
            	   }else {
            		   sum=new ListNode(su);
	            		   l3.next=sum;
	            		   l3=l3.next;
	            		   sign=0; 
            	   }
                 
            	   l1=l1.next;
            	   l2=l2.next;
            
            	
            }
        }
        if(sign==0){
        if(l1!=null) l3.next=l1;
        if(l2!=null) l3.next=l2;
        }else{
            if(l1!=null) {
                l1.val=l1.val+1;
                l3.next=l1;
            }
        else if(l2!=null) {
            l2.val=l2.val+1;
            l3.next=l2;
        }else{
            l3.next=new ListNode(1);
        }
        }
        return res.next;
    }
	
	
}
