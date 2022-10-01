class Solution {
public:
    int trap(vector<int>& height) {
        int l=0;
        int total=0;
        int r=height.size()-1;
        int lmax=0;
        int rmax=0;
         while(l<=r)
         {
             if(height[l]<=height[r])
             {
                 if(height[l]>lmax)
                 {
                    lmax=height[l];
                 }
                 else
                 {
                     total+=lmax-height[l];
                 }
                 l++;
             }
             else
             {
              if(height[r]>rmax)
                 {
                    rmax=height[r];
                 }
                 else
                 {
                     total+=rmax-height[r];
                 }   
                 r--;
             }
         }
        return total;
    }
};