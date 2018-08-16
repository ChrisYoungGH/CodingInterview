/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

#pragma once

struct TreeNode 
{
    int                    val; 
    TreeNode*        left;  
    TreeNode*        right; 
};

TreeNode* CreateTreeNode(int value);
void ConnectTreeNodes(TreeNode* pParent, TreeNode* pLeft, TreeNode* pRight);
void PrintTreeNode(const TreeNode* pNode);
void PrintTree(const TreeNode* pRoot);
void DestroyTree(TreeNode* pRoot);
