/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<pair<int,int>,vector<int>> m;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,vector<int>> m2;
        dfs(root,0,0);
        for(auto i:m){
            vector<int> v=i.second;
            sort(v.begin(),v.end());
            m2[i.first.second].insert(m2[i.first.second].end(), v.begin(), v.end());
        }
        for(auto i:m2){
            vector<int> v=i.second;
            ans.push_back(v);
        }
        return ans;
    }
    
    void dfs(TreeNode* root,int r,int c){
        if(root==NULL) return;
        pair<int, int> p = {r,c};
        m[p].push_back(root->val);
        dfs(root->left,r+1,c-1);
        dfs(root->right,r+1,c+1);
    }
};