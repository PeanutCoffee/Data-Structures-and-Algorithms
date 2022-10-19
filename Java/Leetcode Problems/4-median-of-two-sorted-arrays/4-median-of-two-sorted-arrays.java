class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int s1 = nums1.length;
        int s2 = nums2.length;
        int size = s1+s2;
        int out[] = new int[size];
        // Copy Array1 in new array        
        System.arraycopy(nums1,0,out,0,s1);
        // Copy Array2 in new array        
        System.arraycopy(nums2,0,out,s1,s2);
        // Sort new array        
        Arrays.sort(out);
        // Median
        if (size % 2 != 0) {
            return (double)out[size/2];
        }
        return (double)(out[(size-1)/2] + out[size/2])/2.0;
    }
}