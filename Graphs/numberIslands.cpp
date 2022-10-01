class Solution {
public:
    int n;
    int m;
    void dfs(vector<vector<char>>&grid,int i,int j){
        if(i<0 || i>n-1 || j<0 || j>m-1){
            return;
        }
        if(grid[i][j]!='1'){
            return;
        }
        grid[i][j]='0';
        
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
        
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        int ans =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};
