#include "unordered.h"
#include "../util.h"

bool check_valid(const vector<vector<int>> &matrix){
    return matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2] &&
           matrix[0][1] == matrix[1][2] && matrix[0][1] == matrix[2][3] &&
           matrix[1][0] == matrix[2][1] && matrix[1][3] == matrix[2][4]; 
}

bool Couple::find_couple(vector<vector<int>> nums){
    if (nums.empty()){
        ele_set.push_back(elements);
        vector<vector<int>> matrix = {{0,0}, {0,0,0,0}, {0,0,0,0,0,0}};
        auto ptr = elements.begin();
        for (auto &i : matrix){
            for (auto &j : i){
                j = *ptr;
                ptr++;
            }
        }
        if (check_valid(matrix)){
            print_matrix(matrix);
            return true;
        }
    }
    for (size_t i = 0; i < nums.size(); i++){
        auto num = nums.back();
        nums.pop_back();
        elements.push_back(num[0]);
        elements.push_back(num[1]);
        auto size = elements.size();
        if (find_couple(nums)){
            return true;
        }
        swap(elements[size - 1], elements[size - 2]);
        if (find_couple(nums)){
            return true;
        }
        elements.pop_back();
        elements.pop_back();
        nums.insert(nums.begin(), num);
    }
    return false;
}
