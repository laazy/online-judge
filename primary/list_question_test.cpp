#include "list_question.h"
#include "../main.h"
#include "../util.h"


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

ListNode* succeed_list(ListNode* list, int index){
    ListNode* ans = list;
    for (int i = 0; i < index && ans != NULL; i++){
        ans = ans->next;
    }
    return ans;
}

void test_deleteNode(){
    ListNode* list = initList();
    deleteNode(succeed_list(list, 4));
    print_list(list);
    deleteNode(succeed_list(list, 4));
    print_list(list);
}

void test_removeNthFromEnd(){
    ListNode* list = initList();
    list = removeNthFromEnd(list, 2);
    print_list(list);
    list = removeNthFromEnd(list, 2);
    print_list(list);
    list = initList({1});
    list = removeNthFromEnd(list, 1);
    print_list(list);
}

void test_reverseList(){
    print_list(reverseList(initList()));
}

void test_mergeTwoLists(){
    ListNode* list = mergeTwoLists(initList(), initList());
    print_list(list);

}

void test_isPalindrome(){
    cout << isPalindrome(initList()) << endl;
    cout << isPalindrome(initList({1,1,2,1})) << endl;
    cout << isPalindrome(initList({1,2,3,2,1})) << endl;
}

void test_hasCycle(){
    ListNode *list = initList(), *tail;
    for (tail = list; tail->next != NULL; tail = tail->next);
    tail->next = list->next;
    ListNode *list2 = initList();
    cout << hasCycle(list2) << endl;
    cout << hasCycle(list) << endl;
}

void test_hasCycle2(){
    ListNode *list = initList(), *tail;
    for (tail = list; tail->next != NULL; tail = tail->next);
    tail->next = list->next;
    ListNode *list2 = initList();
    cout << hasCycle2(list2) << endl;
    cout << hasCycle2(list) << endl;
}

int func(){
    test_hasCycle2();
    return 0;
}
