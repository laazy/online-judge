#include "list_question.h"
#include "../util.h"
#include "../main.h"

#define null 0

ListNode* initList(){
    ListNode* list = new ListNode(0);
    ListNode* ptr = list;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i : nums){
        ptr->next = new ListNode(i);
        ptr = ptr->next;
    }
    return list;
}

ListNode* initList(vector<int> nums){
    ListNode* list = new ListNode(0);
    ListNode* ptr = list;
    for (int i : nums){
        ptr->next = new ListNode(i);
        ptr = ptr->next;
    }
    return list->next;
}

void print_list(ListNode* list){
    if (list == NULL){
        cout << "empty list" << endl;
        return;
    }
    ListNode* ptr = list;
    while(ptr != NULL){
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void test_addTwoNumbers(){
    print_list(addTwoNumbers(initList({2,4,3}), initList({5,6,4})));
    print_list(addTwoNumbers(initList({5,4,6}), initList({5,6,4})));
    print_list(addTwoNumbers(initList({7,5,4,3}), initList({5,6,4})));
}

void test_oddEvenList(){
    print_list(oddEvenList(initList({1,2,3,4,5})));
    print_list(oddEvenList(initList({2,1,3,5,6,4,7})));
}

void test_getIntersectionNode(){
    auto l1 = initList({4,1,7,4,5});
    auto l2 = initList({5,0,1});
    l2->next->next->next = l1->next->next;
    cout << getIntersectionNode(l1, l2)->val << endl;
    l1 = initList({2,6,4});
    l2 = initList({1,5});
    cout << getIntersectionNode(l1, l2) << endl;
    l1 = initList({0,9,1,2,4});
    l2 = initList({3});
    l2->next = l1->next->next->next;
    cout << getIntersectionNode(l1, l2)->val <<endl;
}

int func(){
    test_getIntersectionNode();
    return 0;
}
