#ifndef LIST_QUESTION_H
#define LIST_QUESTION_H
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


void deleteNode(ListNode* node);

ListNode* removeNthFromEnd(ListNode* head, int n);

ListNode* reverseList(ListNode* head);

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

bool isPalindrome(ListNode* head);

bool hasCycle(ListNode *head);

bool hasCycle2(ListNode *head);

#endif