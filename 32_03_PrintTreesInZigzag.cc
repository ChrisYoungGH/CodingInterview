// 面试题32（三）：之字形打印二叉树
// 题目：请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺
// 序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，
// 其他行以此类推。

// 解法: 两个栈存奇偶行

#include "utils.h"

class Solution {
public:
	vector<vector<int> > ZigZagPrint(TreeNode *root) {
		vector<vector<int> > res;
		if (!root) return res;

		stack<TreeNode*> levels[2];
		int curr = 0, next = 1;
		levels[0].push(root);

		vector<int> line;

		while (!levels[0].empty() || !levels[1].empty()) {
			TreeNode *node = levels[curr].top();
			levels[curr].pop();
			line.emplace_back(node->val);

			if (!curr) {
				if (node->left) levels[next].push(node->left);
				if (node->right) levels[next].push(node->right);
			}
			else {
				if (node->right) levels[next].push(node->right);
				if (node->left) levels[next].push(node->left);
			}

			if (levels[curr].empty()) {
				res.emplace_back(line);
				line.clear();
				curr = next;
				next = 1 - next;
			}
		}

		return res;
	}
};


void Print(TreeNode* pRoot)
{
    if(pRoot == nullptr)
        return;

    std::stack<TreeNode*> levels[2];
    int current = 0;
    int next = 1;

    levels[current].push(pRoot);
    while(!levels[0].empty() || !levels[1].empty())
    {
        TreeNode* pNode = levels[current].top();
        levels[current].pop();

        printf("%d ", pNode->val);

        if(current == 0)
        {
            if(pNode->left != nullptr)
                levels[next].push(pNode->left);
            if(pNode->right != nullptr)
                levels[next].push(pNode->right);
        }
        else
        {
            if(pNode->right != nullptr)
                levels[next].push(pNode->right);
            if(pNode->left != nullptr)
                levels[next].push(pNode->left);
        }

        if(levels[current].empty())
        {
            printf("\n");
            current = 1 - current;
            next = 1 - next;
        }
    }
}

// ====================²âÊÔ´úÂë====================
//            8
//        6      10
//       5 7    9  11
void Test1()
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

    printf("====Test1 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("8 \n");
    printf("10 6 \n");
    printf("5 7 9 11 \n\n");

    printf("Actual Result is: \n");
    Solution s = Solution();
    vector<vector<int> > res = s.ZigZagPrint(pNode8);
    for (vector<int> level : res) {
    	for (int val : level) {
    		cout << val << " ";
    	}
    	cout << endl;
    }
    printf("\n");

    DestroyTree(pNode8);
}

//            5
//          4
//        3
//      2
void Test2()
{
    TreeNode* pNode5 = CreateTreeNode(5);
    TreeNode* pNode4 = CreateTreeNode(4);
    TreeNode* pNode3 = CreateTreeNode(3);
    TreeNode* pNode2 = CreateTreeNode(2);

    ConnectTreeNodes(pNode5, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode2, nullptr);

    printf("====Test2 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("5 \n");
    printf("4 \n");
    printf("3 \n");
    printf("2 \n\n");

    printf("Actual Result is: \n");
    Solution s = Solution();
    vector<vector<int> > res = s.ZigZagPrint(pNode5);
    for (vector<int> level : res) {
    	for (int val : level) {
    		cout << val << " ";
    	}
    	cout << endl;
    }
    printf("\n");

    DestroyTree(pNode5);
}

//        5
//         4
//          3
//           2
void Test3()
{
    TreeNode* pNode5 = CreateTreeNode(5);
    TreeNode* pNode4 = CreateTreeNode(4);
    TreeNode* pNode3 = CreateTreeNode(3);
    TreeNode* pNode2 = CreateTreeNode(2);

    ConnectTreeNodes(pNode5, nullptr, pNode4);
    ConnectTreeNodes(pNode4, nullptr, pNode3);
    ConnectTreeNodes(pNode3, nullptr, pNode2);

    printf("====Test3 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("5 \n");
    printf("4 \n");
    printf("3 \n");
    printf("2 \n\n");

    printf("Actual Result is: \n");
    Solution s = Solution();
    vector<vector<int> > res = s.ZigZagPrint(pNode5);
    for (vector<int> level : res) {
    	for (int val : level) {
    		cout << val << " ";
    	}
    	cout << endl;
    }
    printf("\n");

    DestroyTree(pNode5);
}

void Test4()
{
    TreeNode* pNode5 = CreateTreeNode(5);

    printf("====Test4 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("5 \n\n");

    printf("Actual Result is: \n");
    Solution s = Solution();
    vector<vector<int> > res = s.ZigZagPrint(pNode5);
    for (vector<int> level : res) {
    	for (int val : level) {
    		cout << val << " ";
    	}
    	cout << endl;
    }
    printf("\n");

    DestroyTree(pNode5);
}

void Test5()
{
    printf("====Test5 Begins: ====\n");
    printf("Expected Result is:\n");

    printf("Actual Result is: \n");
    Solution s = Solution();
    vector<vector<int> > res = s.ZigZagPrint(nullptr);
    for (vector<int> level : res) {
    	for (int val : level) {
    		cout << val << " ";
    	}
    	cout << endl;
    }
    printf("\n");
}

//        100
//        /
//       50   
//         \
//         150
void Test6()
{
    TreeNode* pNode100 = CreateTreeNode(100);
    TreeNode* pNode50 = CreateTreeNode(50);
    TreeNode* pNode150 = CreateTreeNode(150);

    ConnectTreeNodes(pNode100, pNode50, nullptr);
    ConnectTreeNodes(pNode50, nullptr, pNode150);

    printf("====Test6 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("100 \n");
    printf("50 \n");
    printf("150 \n\n");

    printf("Actual Result is: \n");
    Solution s = Solution();
    vector<vector<int> > res = s.ZigZagPrint(pNode100);
    for (vector<int> level : res) {
    	for (int val : level) {
    		cout << val << " ";
    	}
    	cout << endl;
    }
    printf("\n");
}

//                8
//        4              12
//     2     6       10      14
//   1  3  5  7     9 11   13  15
void Test7()
{
    TreeNode* pNode8 = CreateTreeNode(8);
    TreeNode* pNode4 = CreateTreeNode(4);
    TreeNode* pNode12 = CreateTreeNode(12);
    TreeNode* pNode2 = CreateTreeNode(2);
    TreeNode* pNode6 = CreateTreeNode(6);
    TreeNode* pNode10 = CreateTreeNode(10);
    TreeNode* pNode14 = CreateTreeNode(14);
    TreeNode* pNode1 = CreateTreeNode(1);
    TreeNode* pNode3 = CreateTreeNode(3);
    TreeNode* pNode5 = CreateTreeNode(5);
    TreeNode* pNode7 = CreateTreeNode(7);
    TreeNode* pNode9 = CreateTreeNode(9);
    TreeNode* pNode11 = CreateTreeNode(11);
    TreeNode* pNode13 = CreateTreeNode(13);
    TreeNode* pNode15 = CreateTreeNode(15);

    ConnectTreeNodes(pNode8, pNode4, pNode12);
    ConnectTreeNodes(pNode4, pNode2, pNode6);
    ConnectTreeNodes(pNode12, pNode10, pNode14);
    ConnectTreeNodes(pNode2, pNode1, pNode3);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);
    ConnectTreeNodes(pNode14, pNode13, pNode15);

    printf("====Test7 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("8 \n");
    printf("12 4 \n");
    printf("2 6 10 14 \n");
    printf("15 13 11 9 7 5 3 1 \n\n");

    printf("Actual Result is: \n");
    Solution s = Solution();
    vector<vector<int> > res = s.ZigZagPrint(pNode8);
    for (vector<int> level : res) {
    	for (int val : level) {
    		cout << val << " ";
    	}
    	cout << endl;
    }
    printf("\n");

    DestroyTree(pNode8);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}
