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

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

ListNode* CreateListNode(int value)
{
    ListNode* pNode = new ListNode();
    pNode->val = value;
    pNode->next = nullptr;

    return pNode;
}

ListNode *CopyList(ListNode *head) {
    ListNode *headCopy = nullptr;
    ListNode *curr = head, *currCopy = headCopy;
    while (curr) {
        ListNode *copy = new ListNode(curr->val);
        if (!headCopy) {
            headCopy = copy;
            currCopy = headCopy;
        }
        else {
            currCopy->next = copy;
            currCopy = currCopy->next;
        }
        curr = curr->next;
    }

    return headCopy;
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
    if(pCurrent == nullptr)
    {
        printf("Error to connect two nodes.\n");
        exit(1);
    }

    pCurrent->next = pNext;
}

void PrintListNode(ListNode* pNode)
{ 
    if(pNode == nullptr)
    {
        printf("The node is nullptr\n");
    }
    else
    {
        printf("The key in node is %d.\n", pNode->val);
    }
}

void PrintList(ListNode* pHead)
{
    if (!pHead) {
        printf("\n");
        return;
    }

    ListNode* pNode = pHead;
    while(pNode->next) {
        printf("%d->", pNode->val);
        pNode = pNode->next;
    }
    printf("%d\n", pNode->val);
}

void DestroyList(ListNode* pHead)
{
    ListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        pHead = pHead->next;
        delete pNode;
        pNode = pHead;
    }
}

void AddToTail(ListNode** pHead, int value)
{
    ListNode* pNew = new ListNode();
    pNew->val = value;
    pNew->next = nullptr;

    if(*pHead == nullptr)
    {
        *pHead = pNew;
    }
    else
    {
        ListNode* pNode = *pHead;
        while(pNode->next != nullptr)
            pNode = pNode->next;

        pNode->next = pNew;
    }
}

void RemoveNode(ListNode** pHead, int value)
{
    if(pHead == nullptr || *pHead == nullptr)
        return;

    ListNode* pToBeDeleted = nullptr;
    if((*pHead)->val == value)
    {
        pToBeDeleted = *pHead;
        *pHead = (*pHead)->next;
    }
    else
    {
        ListNode* pNode = *pHead;
        while(pNode->next != nullptr && pNode->next->val != value)
            pNode = pNode->next;

        if(pNode->next != nullptr && pNode->next->val == value)
        {
            pToBeDeleted = pNode->next;
            pNode->next = pNode->next->next;
        }
    }

    if(pToBeDeleted != nullptr)
    {
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}

bool CompareList(ListNode *l1, ListNode *l2) {
    ListNode *curr1 = l1, *curr2 = l2;
    while (curr1 && curr2) {
        if (curr1->val != curr2->val) return false;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return !curr1 && !curr2;
}