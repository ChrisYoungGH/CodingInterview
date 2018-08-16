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

struct ListNode
{
    int       val;
    ListNode* next;
    ListNode(int v, ListNode *n) : val(v), next(n) {}
    ListNode(int v) : val(v), next(nullptr) {}
    ListNode() : val(-1), next(nullptr) {}
};

ListNode* CreateListNode(int value);
ListNode* CopyList(ListNode *head);
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext);
void PrintListNode(ListNode* pNode);
void PrintList(ListNode* pHead);
void DestroyList(ListNode* pHead);
void AddToTail(ListNode** pHead, int value);
void RemoveNode(ListNode** pHead, int value);
bool CompareList(ListNode *l1, ListNode *l2);