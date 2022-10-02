class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        helper(satisfaction,0,1,dp);
        return dp[0][0];
    }
    int helper(vector<int>& v,int i,int t,vector<vector<int>> &dp){
        if(i==v.size() || t==v.size()+1) return 0;
        if(dp[i][t-1]!=-1) return dp[i][t-1];
        dp[i][t-1]=max(v[i]*t+helper(v,i+1,t+1,dp),helper(v,i+1,t,dp));
        return dp[i][t-1];
    }
};