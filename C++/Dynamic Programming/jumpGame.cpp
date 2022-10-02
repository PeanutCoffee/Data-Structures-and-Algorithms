class Solution {
public:
    void check(vector<int>&nums,int n,int i,vector<int>&dp){
        if(i<0){
            return;
        }
        if(i==n-1){
            dp[i]= -1;
        }
        else{
            int jump = nums[i];
            for(int j=1;j<=jump;j++){
                if(i+j<=n-1){
                    if(dp[i+j]==-1){
                        dp[i]=-1;
                        break;
                    }
                }
            }
        }
        check(nums,n,i-1,dp);
        return;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,0);
        int i= n-1;
        check(nums,n,i,dp);
        if(dp[0]==-1){
            return true;
        }
        return false;
    }
};
