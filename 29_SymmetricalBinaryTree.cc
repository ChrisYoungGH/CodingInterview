// 面试题28：对称的二叉树
// 题目：请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和
// 它的镜像一样，那么它是对称的。

// 解法: 对称则先序遍历序列==对称先序遍历序列

class Solution {
public:
    bool isSymmetrical(TreeNode* root) {
        return kernel(root, root);
    }
    
    bool kernel(TreeNode *root1, TreeNode *root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        if (root1->val != root2->val) return false;
        return kernel(root1->left, root2->right) && 
               kernel(root1->right, root2->left);
    }

};