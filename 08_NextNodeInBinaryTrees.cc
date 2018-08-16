// 面试题8：二叉树的下一个结点
// 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
// 树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。

// 解法: 有右子树: 右子树的最左节点; 无右子树: 父节点的左孩子是当前节点的节点的父节点

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int	val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    TreeNode(int v, TreeNode *l, TreeNode *r, TreeNode *p) : 
    	val(v), left(l), right(r), parent(p) {}
    TreeNode() : val(-1), left(nullptr), right(nullptr), parent(nullptr) {}
};


class Solution {
public:
	TreeNode *getNextNode(TreeNode *node) {
		if (!node) {
			return nullptr;
		}

		TreeNode *nextNode = nullptr;
		if (node->right) {
			nextNode = node->right;
			while (nextNode->left) {
				nextNode = nextNode->left;
			}
		}
		else {
			TreeNode *curr = node;
			TreeNode *parent = curr->parent;
			while (parent && curr != parent->left) {
				curr = parent;
				parent = curr->parent;
			}
			nextNode = parent;
		}

		return nextNode;
	}
};


// ==================== 辅助代码用来构建二叉树 ====================
class TreeUtils {
public:
	static TreeNode* CreateTreeNode(int value)
	{
	    TreeNode* pNode = new TreeNode();
	    pNode->val = value;
	    pNode->left = nullptr;
	    pNode->right = nullptr;
	    pNode->parent = nullptr;

	    return pNode;
	}

	static void ConnectTreeNodes(TreeNode* pParent, TreeNode* pLeft, TreeNode* pRight)
	{
	    if(pParent != nullptr)
	    {
	        pParent->left = pLeft;
	        pParent->right = pRight;

	        if(pLeft != nullptr)
	            pLeft->parent = pParent;
	        if(pRight != nullptr)
	            pRight->parent = pParent;
	    }
	}

	static void PrintTreeNode(TreeNode* pNode)
	{
	    if(pNode != nullptr)
	    {
	        cout << "value of this node is: %d\n" << pNode->val;

	        if(pNode->left != nullptr)
	            cout << "value of its left child is: %d.\n" << pNode->left->val;
	        else
	            cout << "left child is null." << endl;

	        if(pNode->right != nullptr)
	            cout << "value of its right child is: %d.\n" << pNode->right->val;
	        else
	            cout << "right child is null." << endl;
	    }
	    else
	    {
	        cout << "this node is null." << endl;
	    }

	    cout << "" << endl;
	}

	static void PrintTree(TreeNode* pRoot)
	{
	    PrintTreeNode(pRoot);

	    if(pRoot != nullptr)
	    {
	        if(pRoot->left != nullptr)
	            PrintTree(pRoot->left);

	        if(pRoot->right != nullptr)
	            PrintTree(pRoot->right);
	    }
	}

	static void DestroyTree(TreeNode* pRoot)
	{
	    if(pRoot != nullptr)
	    {
	        TreeNode* pLeft = pRoot->left;
	        TreeNode* pRight = pRoot->right;

	        delete pRoot;
	        pRoot = nullptr;

	        TreeUtils::DestroyTree(pLeft);
	        TreeUtils::DestroyTree(pRight);
	    }
	}
};


// ====================测试代码====================
void Test(string testName, TreeNode* pNode, TreeNode* expected)
{
    if(testName.length())
        cout << testName << " begins: ";

    Solution s = Solution();
    TreeNode* pNext = s.getNextNode(pNode);
    if(pNext == expected)
        cout << "Passed." << endl;
    else
        cout << "FAILED." << endl;
}

//            8
//        6      10
//       5 7    9  11
void Test1_7()
{
    TreeNode* pNode8 = TreeUtils::CreateTreeNode(8);
    TreeNode* pNode6 = TreeUtils::CreateTreeNode(6);
    TreeNode* pNode10 = TreeUtils::CreateTreeNode(10);
    TreeNode* pNode5 = TreeUtils::CreateTreeNode(5);
    TreeNode* pNode7 = TreeUtils::CreateTreeNode(7);
    TreeNode* pNode9 = TreeUtils::CreateTreeNode(9);
    TreeNode* pNode11 = TreeUtils::CreateTreeNode(11);

    TreeUtils::ConnectTreeNodes(pNode8, pNode6, pNode10);
    TreeUtils::ConnectTreeNodes(pNode6, pNode5, pNode7);
    TreeUtils::ConnectTreeNodes(pNode10, pNode9, pNode11);

    Test("Test1", pNode8, pNode9);
    Test("Test2", pNode6, pNode7);
    Test("Test3", pNode10, pNode11);
    Test("Test4", pNode5, pNode6);
    Test("Test5", pNode7, pNode8);
    Test("Test6", pNode9, pNode10);
    Test("Test7", pNode11, nullptr);

    TreeUtils::DestroyTree(pNode8);
}

//            5
//          4
//        3
//      2
void Test8_11()
{
    TreeNode* pNode5 = TreeUtils::CreateTreeNode(5);
    TreeNode* pNode4 = TreeUtils::CreateTreeNode(4);
    TreeNode* pNode3 = TreeUtils::CreateTreeNode(3);
    TreeNode* pNode2 = TreeUtils::CreateTreeNode(2);

    TreeUtils::ConnectTreeNodes(pNode5, pNode4, nullptr);
    TreeUtils::ConnectTreeNodes(pNode4, pNode3, nullptr);
    TreeUtils::ConnectTreeNodes(pNode3, pNode2, nullptr);

    Test("Test8", pNode5, nullptr);
    Test("Test9", pNode4, pNode5);
    Test("Test10", pNode3, pNode4);
    Test("Test11", pNode2, pNode3);

    TreeUtils::DestroyTree(pNode5);
}

//        2
//         3
//          4
//           5
void Test12_15()
{
    TreeNode* pNode2 = TreeUtils::CreateTreeNode(2);
    TreeNode* pNode3 = TreeUtils::CreateTreeNode(3);
    TreeNode* pNode4 = TreeUtils::CreateTreeNode(4);
    TreeNode* pNode5 = TreeUtils::CreateTreeNode(5);

    TreeUtils::ConnectTreeNodes(pNode2, nullptr, pNode3);
    TreeUtils::ConnectTreeNodes(pNode3, nullptr, pNode4);
    TreeUtils::ConnectTreeNodes(pNode4, nullptr, pNode5);

    Test("Test12", pNode5, nullptr);
    Test("Test13", pNode4, pNode5);
    Test("Test14", pNode3, pNode4);
    Test("Test15", pNode2, pNode3);

    TreeUtils::DestroyTree(pNode2);
}

void Test16()
{
    TreeNode* pNode5 = TreeUtils::CreateTreeNode(5);

    Test("Test16", pNode5, nullptr);

    TreeUtils::DestroyTree(pNode5);
}

int main(int argc, char* argv[])
{
    Test1_7();
    Test8_11();
    Test12_15();
    Test16();
}
