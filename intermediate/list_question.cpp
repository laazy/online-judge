#include "list_question.h"

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    int sum = 0, carry = 0;
    ListNode *head = new ListNode(-1), *ptr = head;
    for (; l1 && l2; l1 = l1->next, l2 = l2->next){
        sum = l1->val + l2->val + carry;
        carry = sum >= 10;
        if (sum >= 10){
            sum -= 10;
        }
        ptr->next = new ListNode(sum);
        ptr = ptr->next;
    }
    if (l1 == NULL){
        l1 = l2;
    }
    l2 = ptr;
    if (l1 != NULL){
        for(; l1; l1 = l1->next){
            sum = carry + l1->val;
            carry = sum >= 10;
            if (sum >= 10){
                sum -= 10;
            }
            ptr->next = new ListNode(sum);
            ptr = ptr->next;
        }
    }
    if (carry != 0){
        ptr->next = new ListNode(1);
    }
    ptr = head->next;
    delete head;
    return ptr;
}

ListNode* oddEvenList(ListNode* head){
    if (head == NULL || head->next == NULL || head->next->next == NULL){
        return head;
    }

    ListNode *odd = head, *even = head->next, *odd_p = odd, *even_p = even;
    bool is_even = false;
    for(ListNode *ptr = even->next; ptr != NULL; ptr = ptr->next){
        if (is_even){
            even_p->next = ptr;
            even_p = ptr;
        }else{
            odd_p->next = ptr;
            odd_p = ptr;
        }
        is_even = !is_even;
    }
    
    odd_p->next = even;
    even_p->next = NULL;
    return odd;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
    if (headA == NULL || headB == NULL){
        return NULL;
    }
    auto pa = headA, pb = headB;
    while (pa != pb){
        pa = pa == NULL ? headB : pa->next;
        pb = pb == NULL ? headA : pb->next;
    }
    return pa;
}