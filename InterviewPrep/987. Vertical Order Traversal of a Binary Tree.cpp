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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>m;
        queue<pair<TreeNode*,pair<int,int>>>q;
        vector<vector<int>>ans;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto cur=q.front().first;
            int col=q.front().second.first;
            int row=q.front().second.second;
            q.pop();
            m[col][row].insert(cur->val);
            if(cur->left)
            {
                q.push({cur->left,{col-1,row+1}});
                
            }
            if(cur->right)
            {
                 q.push({cur->right,{col+1,row+1}});
            }
        }
        for(auto it :m)
        {
            vector<int>temp;
            for(auto i:it.second)
            {
                temp.insert(temp.end(),i.second.begin(),i.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};