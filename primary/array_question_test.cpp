#include "array_question.h"
#include "../main.h"

int test_removeDuplicates(){
    vector<int> vec{1,2,3,3,3,4,5,6,6,7,7,7,8};
    cout << removeDuplicates(vec) << endl;
    for (int i : vec){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

int test_maxProfit(vector<int>& prices){
    return 0;
}

int func(){
    return test_removeDuplicates();
}