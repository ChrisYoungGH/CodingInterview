// 面试题54：二叉搜索树的第k个结点
// 题目：给定一棵二叉搜索树，请找出其中的第k大的结点。

// 解法: 中序遍历的写法: 1) 使用引用计数; 2) 使用成员变量计数(更简洁)

#include "utils.h"

class Solution {
public:
	TreeNode *KthNode(TreeNode *root, int k) {
		if (!root || k <= 0) return nullptr;
		return KthNodeCore(root, k);
	}

	TreeNode *KthNodeCore(TreeNode *root, int &k) {
		TreeNode *res = nullptr;
		if (root->left) res = KthNodeCore(root->left, k);

		if (!res) {
			if (k == 1) return root;
			k--;

			if (root->right) res = KthNodeCore(root->right, k);
		}

		return res;
	}
};

class Solution2 {
public:
	TreeNode *KthNode(TreeNode *root, int k) {
		if (!root || k <= 0) return nullptr;

		TreeNode *res = nullptr;
		
		res = KthNode(root->left, k);
		if (res) return res;

		cnt++;
		if (cnt == k) return root;

		res = KthNode(root->right, k);

		return res;
	}

private:
	int cnt = 0;
};


// ====================测试代码====================
void Test(string testName, TreeNode* pRoot, unsigned int k, bool isNull, int expected)
{
    printf("%s begins: ", testName.c_str());
    Solution2 s = Solution2();
    TreeNode* pTarget = s.KthNode(pRoot, k);
    if((isNull && pTarget == nullptr) || (!isNull && pTarget->val == expected))
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//            8
//        6      10
//       5 7    9  11
void TestA()
{
    TreeNode* pNode8 = CreateTreeNode(8);
    TreeNode* pNode6 = CreateTreeNode(6);
    TreeNode* pNode10 = CreateTreeNode(10);
    TreeNode* pNode5 = CreateTreeNode(5);
    TreeNode* pNode7 = CreateTreeNode(7);
    TreeNode* pNode9 = CreateTreeNode(9);
    TreeNode* pNode11 = CreateTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    Test("TestA0", pNode8, 0, true, -1);
    Test("TestA1", pNode8, 1, false, 5);
    Test("TestA2", pNode8, 2, false, 6);
    Test("TestA3", pNode8, 3, false, 7);
    Test("TestA4", pNode8, 4, false, 8);
    Test("TestA5", pNode8, 5, false, 9);
    Test("TestA6", pNode8, 6, false, 10);
    Test("TestA7", pNode8, 7, false, 11);
    Test("TestA8", pNode8, 8, true, -1);

    DestroyTree(pNode8);

    printf("\n\n");
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void TestB()
{
    TreeNode* pNode5 = CreateTreeNode(5);
    TreeNode* pNode4 = CreateTreeNode(4);
    TreeNode* pNode3 = CreateTreeNode(3);
    TreeNode* pNode2 = CreateTreeNode(2);
    TreeNode* pNode1 = CreateTreeNode(1);

    ConnectTreeNodes(pNode5, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode2, nullptr);
    ConnectTreeNodes(pNode2, pNode1, nullptr);

    Test("TestB0", pNode5, 0, true, -1);
    Test("TestB1", pNode5, 1, false, 1);
    Test("TestB2", pNode5, 2, false, 2);
    Test("TestB3", pNode5, 3, false, 3);
    Test("TestB4", pNode5, 4, false, 4);
    Test("TestB5", pNode5, 5, false, 5);
    Test("TestB6", pNode5, 6, true, -1);

    DestroyTree(pNode5);

    printf("\n\n");
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void TestC()
{
    TreeNode* pNode1 = CreateTreeNode(1);
    TreeNode* pNode2 = CreateTreeNode(2);
    TreeNode* pNode3 = CreateTreeNode(3);
    TreeNode* pNode4 = CreateTreeNode(4);
    TreeNode* pNode5 = CreateTreeNode(5);

    ConnectTreeNodes(pNode1, nullptr, pNode2);
    ConnectTreeNodes(pNode2, nullptr, pNode3);
    ConnectTreeNodes(pNode3, nullptr, pNode4);
    ConnectTreeNodes(pNode4, nullptr, pNode5);

    Test("TestC0", pNode1, 0, true, -1);
    Test("TestC1", pNode1, 1, false, 1);
    Test("TestC2", pNode1, 2, false, 2);
    Test("TestC3", pNode1, 3, false, 3);
    Test("TestC4", pNode1, 4, false, 4);
    Test("TestC5", pNode1, 5, false, 5);
    Test("TestC6", pNode1, 6, true, -1);

    DestroyTree(pNode1);

    printf("\n\n");
}

// There is only one node in a tree
void TestD()
{
    TreeNode* pNode1 = CreateTreeNode(1);

    Test("TestD0", pNode1, 0, true, -1);
    Test("TestD1", pNode1, 1, false, 1);
    Test("TestD2", pNode1, 2, true, -1);

    DestroyTree(pNode1);

    printf("\n\n");
}

// empty tree
void TestE()
{
    Test("TestE0", nullptr, 0, true, -1);
    Test("TestE1", nullptr, 1, true, -1);

    printf("\n\n");
}

int main(int argc, char* argv[])
{
    TestA();
    TestB();
    TestC();
    TestD();
    TestE();
}