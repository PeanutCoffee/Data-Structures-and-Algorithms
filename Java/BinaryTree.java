package BinaryTree;

import java.util.*;

class BinaryTreeNode<T> {
    public T data;
    public BinaryTreeNode<T> left;
    public BinaryTreeNode<T> right;

    public BinaryTreeNode(T data){
        this.data = data;
    }
}
class BalancedTreeBetter{
     int height;
     boolean isBalanced;
}
public class BinaryTree {
    
    public static void main(String[] args) {
//        BinaryTreeNode<Integer> root = new BinaryTreeNode<Integer>(1);
//
//        BinaryTreeNode<Integer> rootleft = new BinaryTreeNode<Integer>(2);
//        BinaryTreeNode<Integer> rootright = new BinaryTreeNode<Integer>(3);
//
//        root.left = rootleft;
//        root.right = rootright;

//        printTreeDetailed(root);

//        BinaryTreeNode<Integer> nt = takeTreeInputBetter(true, 0, true);
//        printTreeDetailed(nt);
//        BinaryTreeNode<Integer> root = takeInputLevelWise();
//        printTreeLevelWise(root);
       // printTreeDetailed(root);
//        System.out.println(height(root));
//        System.out.println(numberOfLeafs(root));
        BinaryTreeNode<Integer> root = buildTreeUsingPreorderAndInorder(Arrays.asList(4,2,5,1,6,3,7), Arrays.asList(1,2,4,5,3,6,7));
        printTreeDetailed(root);

    }

    //   Medium    https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
    // Using List but Not working on LeetCode
    public static BinaryTreeNode<Integer> buildTreeUsingPreorderAndInorder(List<Integer> inOrder, List<Integer> preOrder){
        if (inOrder.isEmpty() || preOrder.isEmpty()){
            return null;
        }

        int rootData = preOrder.get(0);
        BinaryTreeNode<Integer> root = new BinaryTreeNode<>(rootData);

        int rootIndexInorder = 0;
        for (int i = 0; i < inOrder.size();i++){
            if (rootData == inOrder.get(i)){
                rootIndexInorder = i;
                break;
            }
        }
        List<Integer> leftInorder = new ArrayList<>(inOrder.subList(0,rootIndexInorder));
        List<Integer> rightInorder = new ArrayList<>(inOrder.subList(rootIndexInorder+1, inOrder.size()));

        List<Integer> leftPreOrder = new ArrayList<>(preOrder.subList(1, leftInorder.size() + 1));
        List<Integer> rightPreOrder = new ArrayList<>(preOrder.subList(leftInorder.size() + 1, preOrder.size()));

        root.left = buildTreeUsingPreorderAndInorder(leftInorder, leftPreOrder);
        root.right = buildTreeUsingPreorderAndInorder(rightInorder, rightPreOrder);

        return root;

    }



    //Print Level Wise data
    public static void printTreeLevelWise(BinaryTreeNode<Integer> root){
        if (root == null){
            return;
        }

        Queue<BinaryTreeNode<Integer>> pendingChildrenToPrint = new LinkedList<BinaryTreeNode<Integer>>() ;
        pendingChildrenToPrint.add(root);

        while (!pendingChildrenToPrint.isEmpty()){
            BinaryTreeNode<Integer> front = pendingChildrenToPrint.poll();
            System.out.print(front.data + " : ");
            if(front.left != null){
                pendingChildrenToPrint.add(front.left);
                System.out.print("L"+front.left.data);
            }
            if(front.right != null){
                pendingChildrenToPrint.add(front.right);
                System.out.print(", R"+ front.right.data);
            }
            System.out.println();

        }

    }

    // Take Level Wise Input
    public static BinaryTreeNode<Integer> takeInputLevelWise(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter root data");
        int rootData = sc.nextInt();
        if (rootData == -1){
            return null;
        }
        BinaryTreeNode<Integer> root = new BinaryTreeNode<Integer>(rootData);
        Queue<BinaryTreeNode<Integer>> pendingChildren = new LinkedList<BinaryTreeNode<Integer>>();
        pendingChildren.add(root);

        while(!pendingChildren.isEmpty()){
            BinaryTreeNode<Integer> front = pendingChildren.poll();
            System.out.println("Enter left Child of " + front.data);
            int leftChild = sc.nextInt();
            if (leftChild != -1){
                BinaryTreeNode<Integer> left = new BinaryTreeNode<Integer>(leftChild);
                front.left = left;
                pendingChildren.add(left);
            }


            System.out.println("Enter right Child of " + front.data);
            int rightChild = sc.nextInt();
            if (rightChild != -1){
                BinaryTreeNode<Integer> right = new BinaryTreeNode<Integer>(rightChild);
                front.right = right;
                pendingChildren.add(right);
            }


        }
        return root;
    }

    //isBalanced better version Easy  https://leetcode.com/problems/balanced-binary-tree/

    public static BalancedTreeBetter isBalancedBetter(BinaryTreeNode<Integer> root){
        if (root == null){
            int height = 0;
            boolean isBalanced = true;
            BalancedTreeBetter ans = new BalancedTreeBetter();
            ans.height = height;
            ans.isBalanced = isBalanced;
            return ans;
        }
        BalancedTreeBetter leftBalanced = isBalancedBetter(root.left);
        BalancedTreeBetter rightBalanced = isBalancedBetter(root.right);
        int height = 1 + Math.max(leftBalanced.height, rightBalanced.height);
        boolean isBal = true;
        if (Math.abs(leftBalanced.height - rightBalanced.height) > 1){
            isBal = false;
        }
        if (!leftBalanced.isBalanced || !rightBalanced.isBalanced){
            isBal = false;
        }
        BalancedTreeBetter ans = new BalancedTreeBetter();
        ans.height = height;
        ans.isBalanced = isBal;
        return ans;
    }

    public static BinaryTreeNode<Integer> removeLeaves(BinaryTreeNode<Integer> root){
        if (root == null){
            return null;
        }
        if (root.left == null && root.right == null){
            return null;
        }
        root.left = removeLeaves(root.left);
        root.right = removeLeaves(root.right);
        return root;
    }

    // Replace Node with Depth  (below explanation and code)
//    For a given a Binary Tree of integers, replace each of its data with the depth of the tree.
//    Root is at depth 0, hence the root data is updated with 0. Replicate the same further going down the in the depth of the given tree.
//    The modified tree will be printed in the in-order fashion.
    public static void changeToDepthTree(BinaryTreeNode<Integer> root){
        changeToDepthTreeHelper(root, 0);
    }
    private static void changeToDepthTreeHelper(BinaryTreeNode<Integer> root, int level){
        if (root == null){
            return;
        }
        root.data = level;

        changeToDepthTreeHelper(root.left, level+1);
        changeToDepthTreeHelper(root.right, level+1);

    }
  //  End of replace node with depth

    public static void printAtDepthK(BinaryTreeNode<Integer> root, int k){
        if (root == null){
            return;
        }
        if (k == 0){
            System.out.println(root.data);
            return;
        }
        printAtDepthK(root.left,k-1);
        printAtDepthK(root.right,k-1);
    }

    public static int numberOfLeafs(BinaryTreeNode<Integer> root){
        if (root == null){
            return 0;
        }
        if (root.left == null && root.right == null){
            return 1;
        }
        return numberOfLeafs(root.left) + numberOfLeafs(root.right);
    }

    public static int height(BinaryTreeNode<Integer> root){
        if (root == null){
            return 0;
        }
        return 1 + Math.max(height(root.left), height(root.right));
    }
//    If binary tree has height h, minimum number of nodes is h+1 (in case of left skewed and right skewed binary tree).
//      Source  = https://www.geeksforgeeks.org/relationship-number-nodes-height-binary-tree/
//    For example, the binary tree shown in Figure 2(a) with height 2 has 3 nodes.
//    If binary tree has height h, maximum number of nodes will be when all levels are completely full. Total number of nodes will be 2^0 + 2^1 + …. 2^h = 2^(h+1)-1.
//    For example, the binary tree shown in Figure 2(b) with height 2 has 2^(2+1)-1 = 7 nodes.

    public static int countNodesGreaterThanX(BinaryTreeNode<Integer> root, int x){
        if (root == null){
            return 0;
        }
        int count = (root.data > x) ?  1 : 0;
        if (root.left != null){
            count += countNodesGreaterThanX(root.left, x);
        }
        if (root.right != null){
            count += countNodesGreaterThanX(root.right, x);
        }
        return count;
    }

    public static int largest(BinaryTreeNode<Integer> root){
        if (root == null){
            return -1;
        }
        int largestLeft = largest(root.left);
        int largestRight = largest(root.right);

        return Math.max(root.data, Math.max(largestLeft, largestRight));
    }
  

    public static void preOrder(BinaryTreeNode<Integer> root){
        if (root == null){
            return;
        }
        System.out.println(root.data + " ");
        preOrder(root.left);
        preOrder(root.right);
    }

    public static void postOrder(BinaryTreeNode<Integer> root){
        if (root == null){
            return;
        }
        postOrder(root.left);
        postOrder(root.right);

        System.out.println(root.data + " ");
    }

    public static void inOrder(BinaryTreeNode<Integer> root){
        if (root == null){
            return;
        }
        inOrder(root.left);
        System.out.println(root.data + " ");
        inOrder(root.right);
    }

    public static int numNode(BinaryTreeNode<Integer> root){
       if (root == null){
           return 0;
       }
       int leftNodeCount = numNode(root.left);
       int rightNodeCount = numNode(root.right);
       return 1 + leftNodeCount + rightNodeCount;
    }

    public static int getSum(BinaryTreeNode<Integer> root){
       if (root == null){
           return 0;
       }
       int leftNodesum = getSum(root.left);
       int rightNodeSum = getSum(root.right);
       return root.data + leftNodesum+rightNodeSum;
    }

    public static BinaryTreeNode<Integer> takeTreeInputBetter(boolean isRoot, int parentData, boolean isLeft){
       if (isRoot){
           System.out.println("Enter root data : ");
       }else{
           if (isLeft){
               System.out.println("Enter Left child of "+ parentData);
           }else {
               System.out.println("Enter right child of "+ parentData);
           }
       }

        Scanner sc = new Scanner(System.in);
        int rootdata = sc.nextInt();

        if (rootdata == -1){
            return null;
        }
        BinaryTreeNode<Integer> root = new BinaryTreeNode<Integer>(rootdata);

        BinaryTreeNode<Integer> leftChild = takeTreeInputBetter(false, rootdata, true);
        BinaryTreeNode<Integer> rightChild = takeTreeInputBetter(false, rootdata, false);
        root.left = leftChild;
        root.right = rightChild;


        return root;

    }

    public static BinaryTreeNode<Integer> takeTreeInput(){
        System.out.println("Enter root data , Enter -1 for null ?");
        Scanner sc = new Scanner(System.in);
        int rootdata = sc.nextInt();

        if (rootdata == -1){
            return null;
        }
        BinaryTreeNode<Integer> root = new BinaryTreeNode<Integer>(rootdata);

        BinaryTreeNode<Integer> leftChild = takeTreeInput();
        BinaryTreeNode<Integer> rightChild = takeTreeInput();
        root.left = leftChild;
        root.right = rightChild;

        System.out.println("Enter Left root data");
        return root;

    }

    public static void printTreeDetailed(BinaryTreeNode<Integer> root){
        if (root == null){
            return;
        }
        System.out.print(root.data + " : ");
        if(root.left != null){
            System.out.print("L "+ root.left.data+ ", ");
        }
        if(root.right != null){
            System.out.print("R "+ root.right.data);
        }
        System.out.println();
        printTreeDetailed(root.left);
        printTreeDetailed(root.right);
    }

    public static void printTree(BinaryTreeNode<Integer> root){
        if (root == null){
            return;
        }
        System.out.println(root.data);
        printTree(root.left);
        printTree(root.right);

//        if(root.left != null){
//            printTree(root.left);
//        }
//        if(root.right != null){
//            printTree(root.right);
//        }
    }
}

