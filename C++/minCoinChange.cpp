#include <bits/stdc++.h>

using namespace std;

int minCoinChange(vector<int>& deno, int T){
    
    int n= deno.size();
    
    vector<vector<int>> dp(n,vector<int>(T+1,0));
    
    for(int i=0; i<=T; i++){
        if(i%deno[0] == 0)  
            dp[0][i] = i/deno[0];
        else dp[0][i] = INT_MAX;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=T; target++){
            
            int notTake = 0 + dp[ind-1][target];
            int take = INT_MAX;
            if(deno[ind]<=target)
                take = 1 + dp[ind][target - deno[ind]];
                
             dp[ind][target] = min(notTake, take);
        }
    }
    
    int ans = dp[n-1][T];
    if(ans >=INT_MAX) return -1;
    return ans;
}

int main() {

  vector<int> arr ={1,2,3,5};
  int T=10;
                                 
  cout<<"The minimum number of coins required to form the target sum is " 
  <<minCoinChange(arr,T);
}
