#include "sort_search.h"

/**
 * 这里的ptr 和 ptr_2加起来扫描了一次数组，ptr_0只是为了简化代码，实际上可以采用记录1的数量cnt_1，然后ptr - cnt_1来确定ptr_0
 */ 
void sortColors(vector<int>& nums){
    auto ptr_0 = nums.begin(), ptr_2 = nums.end();
    for (auto ptr = nums.begin(); ptr != ptr_2;){
        switch (*ptr)
        {
            case 0:
                swap(*ptr, *ptr_0);
                ptr_0++;
                ptr++;
                break;
            case 2:
                ptr_2--;
                swap(*ptr, *ptr_2);
                break;
            default:
                ptr++;
                break;
        }
    }
}