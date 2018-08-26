// 面试题68：树中两个结点的最低公共祖先
// 题目：输入两个树结点，求它们的最低公共祖先。树是二叉搜索树.

// 解法: 与根节点比较大小, 都小在左边, 都大在右边, 一大一小则祖先是根.

class Solution {
public:
	TreeNode* GetLastCommonNode(TreeNode *root, TreeNode *node1, TreeNode *node2) {
		if (node1 == node2) return node1;
		
		if (!root || !node1 || !node2
			|| node1->val == root->val || node2->val == root->val
			|| (node1->val <= root->val && node2->val >= root->val)
			|| (node1->val >= root->val && node2->val >= root->val)) {
			return root;
		}

		if (node1->val < root->val && node2->val < root->val) {
			return GetLastCommonNode(root->left, node1, node2);
		}
		else return GetLastCommonNode(root->right, node1, node2);
	}
};