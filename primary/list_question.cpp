#include "list_question.h"

void deleteNode(ListNode* node){
    node->val = node->next->val;
    node->next = node->next->next;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy = ListNode(0);
    dummy.next = head;
    ListNode *p = head, *q = &dummy;
    while (n){
        p = p->next;
        n--;
    }
    while(p != NULL){
        p = p->next;
        q = q->next;
    }
    q->next = q->next->next;
    return dummy.next;
}

ListNode* reverseList(ListNode* head) {
    if (head == NULL || head->next == NULL){
        return head;
    }
    ListNode *pre, *cur = head, *next = head->next;
    head->next = NULL;
    while (next){
        pre = cur;
        cur = next;
        next = next->next;
        cur->next = pre;
    }
    return cur;
}

// 自我感觉写的比答案好
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode list = ListNode(0), *ptr;
    ptr = &list;
    ListNode **list_ptr;
    while (l1 != NULL && l2 != NULL){
        list_ptr = l1->val < l2->val ? &l1 : &l2;
        ptr->next = *list_ptr;
        *list_ptr = (*list_ptr)->next;
        ptr = ptr->next;
    }
    ptr->next = l1 != NULL ? l1 : l2;
    return list.next;
}

/**
 * 这题分为几步：
 *  一：先找到中间节点 时间复杂度O(n) 空间复杂度O(1)
 *  二：将中间节点之后的列表翻转 时间复杂度O(n) 空间复杂度O(1)
 *  三：比较两个列表 时间复杂度O(n) 空间复杂度O(1)
 *  总计时间复杂度O(n) 空间复杂度O(1)
 */ 
bool isPalindrome(ListNode* head) {
    if (head == NULL){
        return true;
    }
    int size = 0;
    ListNode* ptr = head, *half = head;
    for(; ptr != NULL; ptr = ptr->next){
        size++;
        if (size % 2 == 0){
            half = half->next;
        }
    }
    ListNode *pre, *cur = half, *next = half->next;
    half->next = NULL;
    while (next){
        pre = cur;
        cur = next;
        next = next->next;
        cur->next = pre;
    }
    half = cur;
    for (ptr = head; ptr != NULL && half != NULL; ptr = ptr->next, half = half->next){
        if (ptr->val != half->val){
            return false;
        }
    }
    return true;
}

// 空间复杂度为O(n) 时间复杂度为O(n)
bool hasCycle(ListNode *head) {
    unordered_map<ListNode*, int> table;
    for (; head != NULL; head = head->next){
        if (table.find(head) == table.end()){
            table[head] = 1;
        }else{
            return true;
        }
    }
    return false;
}

// 空间复杂度为O(1) 时间复杂度为O(n)
bool hasCycle2(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while (fast && slow){
        fast = fast->next;
        if (!fast){
            return false;
        }
        fast = fast->next;
        slow = slow->next;
        if (fast == slow){
            return true;
        }
    }
    return false;
}
