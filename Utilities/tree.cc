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

#include "tree.h"

CommonTreeNode* CreateCommonTreeNode(int value)
{
    CommonTreeNode* pNode = new CommonTreeNode();
    pNode->m_nValue = value;

    return pNode;
}

void ConnectCommonTreeNodes(CommonTreeNode* pParent, CommonTreeNode* pChild)
{
    if(pParent != nullptr)
    {
        pParent->m_vChildren.push_back(pChild);
    }
}

void PrintCommonTreeNode(const CommonTreeNode* pNode)
{
    if(pNode != nullptr)
    {
        printf("value of this node is: %d.\n", pNode->m_nValue);

        printf("its children is as the following:\n");
        std::vector<CommonTreeNode*>::const_iterator i = pNode->m_vChildren.begin();
        while(i < pNode->m_vChildren.end())
        {
            if(*i != nullptr)
                printf("%d\t", (*i)->m_nValue);
        }

        printf("\n");
    }
    else
    {
        printf("this node is nullptr.\n");
    }

    printf("\n");
}

void PrintTree(const CommonTreeNode* pRoot)
{
    PrintCommonTreeNode(pRoot);

    if(pRoot != nullptr)
    {
        std::vector<CommonTreeNode*>::const_iterator i = pRoot->m_vChildren.begin();
        while(i < pRoot->m_vChildren.end())
        {
            PrintTree(*i);
            ++i;
        }
    }
}

void DestroyTree(CommonTreeNode* pRoot)
{
    if(pRoot != nullptr)
    {
        std::vector<CommonTreeNode*>::iterator i = pRoot->m_vChildren.begin();
        while(i < pRoot->m_vChildren.end())
        {
            DestroyTree(*i);
            ++i;
        }

        delete pRoot;
    }
}
