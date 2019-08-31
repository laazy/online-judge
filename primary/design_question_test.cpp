#include "../main.h"
#include "../util.h"
#include "design_question.h"

void test_Shuffle_an_Array(){
    vector<int> nums = {1, 2, 3};
    Solution solution = Solution(nums);
    vector<vector<int>> total = {{0,0,0},{0,0,0},{0,0,0}};
    for (int i = 0; i < 9000000; i++){
        vector<int> temp = solution.shuffle();
        for (size_t j = 0; j < nums.size(); j++){
            total[j][temp[j] - 1]++;
        }
    }
    print_matrix(total);
    // print_vec(solution.shuffle());
    // print_vec(solution.shuffle());
    // print_vec(solution.shuffle());
    // print_vec(solution.shuffle());
    print_vec(solution.reset());
}

void test_MinStack(){
    MinStack minStack = MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << (minStack.getMin() == -3) << endl;
    minStack.pop();
    cout << (minStack.top() == 0) << endl;
    cout << (minStack.getMin() == -2) << endl;
}

int func(){
    test_MinStack();
    return 0;
}