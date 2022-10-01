class Solution {
public:
    struct TreeDS{
        int sum,maxLeft,minRight;
        bool isBST;
        TreeDS(){
            sum=0;
            maxLeft=INT_MIN;
            minRight=INT_MAX;
            isBST=false;
        }
    };
    TreeDS func(TreeNode* root,int &ans){
        TreeDS T;
        if(!root){ T.isBST=true;return T;}
        TreeDS left=func(root->left, ans);
        TreeDS right=func(root->right, ans);
        if(!left.isBST || !right.isBST || left.maxLeft>=root->val || right.minRight<=root->val) {return T;}
        T.isBST=true;
        T.sum=root->val+left.sum+right.sum;
        T.maxLeft=max(root->val,right.maxLeft);
        T.minRight=min(root->val,left.minRight);
        ans=max(ans,T.sum);
        return T;
    }
    
    int maxSumBST(TreeNode* root) {
        int ans=0;
        func(root,ans);
        return ans;
    }
};