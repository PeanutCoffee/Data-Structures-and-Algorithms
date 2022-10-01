import java.util.ArrayList;
import java.util.List;

import javax.swing.tree.TreeNode;

class Solution {
    public static void inorder(TreeNode root,List<Integer> al)
    {
        // proceed if root is not null
        if(root!=null)
        {
            // Go to left side
            inorder(root.left,al);
            // insert root node
            al.add(root.val);
            // Go to right side
            inorder(root.right,al);
        }
    }
    public List<Integer> inorderTraversal(TreeNode root) {
        // Make answer list that stores the result
        List<Integer> ans=new ArrayList<>();
        // function that find out inorder traversal of tree and store in ans List
        inorder(root,ans);
        return ans;
    }
}