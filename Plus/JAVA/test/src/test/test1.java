package test;

public class test1 {


	    public int[] twoSum(int[] nums, int target) {
	        int i,j,mi = 0,mj=0;
	        int max=0;
	        for(i=0;i<nums.length;i++){
	            for(j=i;j<nums.length;j++){
	                
	                if(nums[i]+nums[j]<target&&nums[i]+nums[j]>max){
	                    max=nums[i]+nums[j];
	                    mi=i;
	                    mj=j;
	                }
	            }
	        }
	        if(mi==mj) return null;
	        int[] x= {mi,mj};
	        return x;
	    }
	}

