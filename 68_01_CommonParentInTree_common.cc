// 面试题68：树中两个结点的最低公共祖先
// 题目：输入两个树结点，求它们的最低公共祖先。

// 解法: 如果两个节点相同, 则该节点就是; 如果根等于其中一个节点, 则根就是; 否则看左右是否有某个节点的祖先,
// 左右都有则根才是, 否则两个节点的祖先集中在一边, 找到的这个是祖先.

class Solution {
public:
	TreeNode* GetLastCommonNode(TreeNode *root, TreeNode *node1, TreeNode *node2) {
		if (node1 == node2) {
			return node1;
		}

		if (!root || root == node1 || root == node2) {
			return root;
		}

		TreeNode *left = GetLastCommonNode(root->left, node1, node2);
		TreeNode *right = GetLastCommonNode(root->right, node1, node2);

		if (left && right) {
			return root;
		}
		return left ? left : right;
	}
};