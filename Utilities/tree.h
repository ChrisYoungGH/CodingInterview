/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

#pragma once

#include <vector>
#include <cstdio>

struct CommonTreeNode 
{
    int                       m_nValue;    
    std::vector<CommonTreeNode*>    m_vChildren;    
};

CommonTreeNode* CreateCommonTreeNode(int value);
void ConnectCommonTreeNodes(CommonTreeNode* pParent, CommonTreeNode* pChild);
void PrintCommonTreeNode(const CommonTreeNode* pNode);
void PrintTree(const CommonTreeNode* pRoot);
void DestroyTree(CommonTreeNode* pRoot);
