package test;

public class test3 {
	public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int num=nums1.length+nums2.length;
        int index1=0,index2=0;
        if(num%2==0){
            
            for(int i=0;i<=(nums1.length+nums2.length)/2-1;i++){
                 if(nums1[index1]>nums2[index2]){
                     index1++;
                 }else{
                    index2++;       
                 }
            }
            return ((double)nums1[index1]+(double)nums2[index2])/2;
            
            
        }else{
            
        
            for(int i=0;i<=(nums1.length+nums2.length)/2;i++){
                 if(nums1[index1]>nums2[index2]){
                     index1++;
                 }else{
                    index2++;       
                 }
            }
            int res ; if(nums1[index1]>nums2[index2]) res=nums2[index2] ;else res =nums1[index1];
            return res;
            
        }
    }
}
