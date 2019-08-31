#include "unordered.h"
#include "../util.h"

bool check_valid(const vector<int> &nums){
    vector<vector<int>> matrix = {{0,0}, {0,0,0,0}, {0,0,0,0,0,0}};
    auto ptr = nums.begin();
    for (auto &i : matrix){
        for (auto &j : i){
            j = *ptr;
            ptr++;
        }
    }
    return matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2] &&
           matrix[0][1] == matrix[1][2] && matrix[0][1] == matrix[2][3] &&
           matrix[1][0] == matrix[2][1] && matrix[1][3] == matrix[2][4]; 
}

bool Couple::find_couple(vector<vector<int>> nums){
    if (nums.empty() && check_valid(elements)){
        return true;
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
        // nums.push_back(num);
    }
    return false;
}

int smallest_element(vector<int> &A){
    if (A.size() == 0){
        return 1;
    }
    sort(A.begin(), A.end());
    
    int smallest = 0;
    for (auto i : A){
        if (i < 0){
            continue;
        }
        if (i - 1 > smallest){
            break;
        }
        smallest = i;
    }
    return smallest + 1;
}

int int_time_string(int D, string &S){
    if (S == "one"){
        return D * 1;
    }else if (S == "two"){
        return D * 2;
    }else if (S == "three"){
        return D * 3;
    }else if (S == "four"){
        return D * 4;
    }else if (S == "five"){
        return D * 5;
    }
    return -1; 
}

int vacation_time(int Y, string &A, string &B, string &W){
    int days_of_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int first_day = -1;
    int total_day = 0;
    int begin_month = -1;
    int end_month = -1;
    if (Y % 4 == 0){
        days_of_month[1]++;
    }
    vector<string> weekday {"Monday", "Tuesday", "Wednesday", "Thursday"
        "Friday", "Saturday", "Sunday"};
    vector<string> months {"January", "February", "March", "April", "May", 
        "June", "July", "August", "September", "October", "November", "December"};
    for (size_t i = 0; i < weekday.size(); i++){
        if (weekday[i] == W){
            first_day = i;
            break;
        }
    }

    for (size_t i = 0; i < months.size(); i++){
        if (months[i] == A){
            begin_month = i;
        }
        if (months[i] == B){
            end_month = i;
        }
    }

    for (int i = begin_month; i <= end_month; i++){
        total_day += days_of_month[i];
    }

    for (int i = 0; i < begin_month; i++){
        first_day = (first_day + days_of_month[i]) % 7;
    }
    if (first_day != 0){
        total_day -= (7 - first_day);
    }
    return total_day / 7;
}
