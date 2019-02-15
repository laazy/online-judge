#include "array_question.h"
#include "../main.h"

void print_vec(const vector<int> &vec){
    for (int i : vec){
        cout << i << " ";
    }
    cout << endl;
}

void print_matrix(const vector<vector<int>> &mat){
    for (auto i : mat){
        print_vec(i);
    }
}

void test_removeDuplicates(){
    vector<int> vec{1,2,3,3,3,4,5,6,6,7,7,7,8};
    cout << removeDuplicates(vec) << endl;
    print_vec(vec);
}

void test_maxProfit(){
    vector<int> vec1{7,1,5,3,6,4};
    vector<int> vec2{1,2,3,4,5};
    cout << maxProfit(vec1) << " " << maxProfit(vec2) << endl;
}

void test_rotate(){
    vector<int> vec{1,2,3,3,3,4,5,6,6,7,7,7,8};
    rotate(vec, 2);
    print_vec(vec);
}

void test_containsDuplicate() {
    vector<int> vec1{1,2,3,3,3,4,5,6,6,7,7,7,8};
    vector<int> vec2{1,2,3,4,5,6,7,8,9,0};
    cout << containsDuplicate(vec1) << endl;
    cout << containsDuplicate(vec2) << endl;
}

void test_singleNumber() {
    vector<int> vec1{1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,7,8,9,0};
    vector<int> vec2{1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,8,9,0};
    vector<int> vec3{2,2,1};
    cout << singleNumber(vec1) << endl;
    cout << singleNumber(vec3) << endl;
}

void test_intersect(){
    vector<int> vec1{1,2,2,1};
    vector<int> vec2{2,2};
    print_vec(intersect(vec1, vec2));
}
void test_plusOne(){
    vector<int> vec1{1,2,2,1};
    vector<int> vec2{1,9,9,9};
    vector<int> vec3{9,9,9};
    print_vec(plusOne(vec1));
    print_vec(plusOne(vec2));
    print_vec(plusOne(vec3));
}

void test_moveZeroes() {
    vector<int> vec1{1,0,2,3,0,0};
    vector<int> vec2{0,1,0,3,12};
    vector<int> vec3{9, 9, 9};
    moveZeroes(vec1);
    moveZeroes(vec2);
    moveZeroes(vec3);
    print_vec(vec1);
    print_vec(vec2);
    print_vec(vec3);
}

void test_twoSum() {
    vector<int> vec1{2, 7, 11, 15};
    vector<int> vec2{3, 2, 4};
    vector<int> vec3{3, 3};
    print_vec(twoSum(vec1, 9));
    print_vec(twoSum(vec2, 6));
    print_vec(twoSum(vec3, 6));
}

void test_isValidSudoku(){
    vector<vector<char>> sudoku1 = {
        {'5','3','.',  '.','7','.',  '.','.','.'},
        {'6','.','.',  '1','9','5',  '.','.','.'},
        {'.','9','8',  '.','.','.',  '.','6','.'},

        {'8','.','.',  '.','6','.',  '.','.','3'},
        {'4','.','.',  '8','.','3',  '.','.','1'},
        {'7','.','.',  '.','2','.',  '.','.','6'},

        {'.','6','.',  '.','.','.',  '2','8','.'},
        {'.','.','.',  '4','1','9',  '.','.','5'},
        {'.','.','.',  '.','8','.',  '.','7','9'}
    };
    vector<vector<char>> sudoku2 = {
        {'8','3','.',  '.','7','.',  '.','.','.'},
        {'6','.','.',  '1','9','5',  '.','.','.'},
        {'.','9','8',  '.','.','.',  '.','6','.'},

        {'8','.','.',  '.','6','.',  '.','.','3'},
        {'4','.','.',  '8','.','3',  '.','.','1'},
        {'7','.','.',  '.','2','.',  '.','.','6'},

        {'.','6','.',  '.','.','.',  '2','8','.'},
        {'.','.','.',  '4','1','9',  '.','.','5'},
        {'.','.','.',  '.','8','.',  '.','7','9'}
    };
    cout << isValidSudoku(sudoku1) << endl;
    cout << isValidSudoku(sudoku2) << endl;
}

void test_rotateMatrix(){
    vector<vector<int>> matrix1 = {
        { 5, 1, 9,11},
        { 2, 4, 8,10},
        {13, 3, 6, 7},
        {15,14,12,16}
    };
    vector<vector<int>> matrix2 = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    rotateMatrix2(matrix1);
    rotateMatrix2(matrix2);
    print_matrix(matrix1);
    print_matrix(matrix2);
}

int func(){
    test_maxProfit();
    // test();
    return 0;
    // return test_removeDuplicates();
}