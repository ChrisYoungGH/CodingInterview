// 面试题18（一）：在O(1)时间删除链表结点
// 题目：给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该
// 结点。

// 解法: O(1): 如果删除的节点有下一个节点, 则直接将下一个节点的值填在当前节点之后删除下一个节点

#include "utils.h"

class Solution {
public:
    ListNode* deleteNode(ListNode *head, ListNode *node) {
        if (!head || !node) {
            return nullptr;
        }

        ListNode *toBeDeleted = nullptr;
        // 要删除的节点为头节点
        if (node == head) {
            toBeDeleted = head;
            head = head->next;
        }
        else {
            // 要删除的节点有下一个节点
            if (node->next) {
                toBeDeleted = node->next;
                node->val = toBeDeleted->val;
                node->next = toBeDeleted->next;
            }
            else {
                // 要删除的节点没有下一个节点
                ListNode *curr = head;
                while (curr && curr->next != node) {
                    curr = curr->next;
                }
                // 要删除的节点在链表中则删除
                if (curr) {
                    toBeDeleted = curr->next;
                    curr->next = nullptr;
                }
            }
        }

        // 释放内存
        if (toBeDeleted) delete toBeDeleted;

        return head;
    }
};

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
    if(!pListHead || !pToBeDeleted)
        return;

    // 要删除的结点不是尾结点
    if(pToBeDeleted->next != nullptr)
    {
        ListNode* pNext = pToBeDeleted->next;
        pToBeDeleted->val = pNext->val;
        pToBeDeleted->next = pNext->next;
 
        delete pNext;
        pNext = nullptr;
    }
    // 链表只有一个结点，删除头结点（也是尾结点）
    else if(*pListHead == pToBeDeleted)
    {
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
        *pListHead = nullptr;
    }
    // 链表中有多个结点，删除尾结点
    else
    {
        ListNode* pNode = *pListHead;
        while(pNode->next != pToBeDeleted)
        {
            pNode = pNode->next;            
        }
 
        pNode->next = nullptr;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}

// ====================测试代码====================
void Test(string testName, ListNode* pListHead, ListNode* pNode)
{
    ListNode *copyHead = CopyList(pListHead);
    ListNode *pNodeCopy = copyHead;
    while (pNodeCopy && pNode && pNodeCopy->val != pNode->val) {
        pNodeCopy = pNodeCopy->next;
    }
    if (!pNodeCopy && pNode) {
        pNodeCopy = new ListNode(pNode->val);
    }

    Solution s = Solution();
    copyHead = s.deleteNode(copyHead, pNodeCopy);

    DeleteNode(&pListHead, pNode);
    bool correct = CompareList(pListHead, copyHead);

    cout << testName << " " << (correct ? "pass" : "FAILED") << "." << endl;
}

// 链表中有多个结点，删除中间的结点
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test("Test1", pNode1, pNode3);

    DestroyList(pNode1);
}

// 链表中有多个结点，删除尾结点
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test("Test2", pNode1, pNode5);

    DestroyList(pNode1);
}

// 链表中有多个结点，删除头结点
void Test3()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test("Test3", pNode1, pNode1);

    DestroyList(pNode1);
}

// 链表中只有一个结点，删除头结点
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);

    Test("Test4", pNode1, pNode1);
}

// 链表为空
void Test5()
{
    Test("Test5", nullptr, nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}