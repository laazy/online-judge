#ifndef LIST_QUESTION_H
#define LIST_QUESTION_H
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

ListNode* oddEvenList(ListNode* head);

#endif
