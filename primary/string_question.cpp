#include "string_question.h"

void reverseString(vector<char>& s) {
    int total = s.size() / 2, j = s.size() - 1, temp;
    for (int i = 0; i < total; i++){
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        j--;
    }
}

int reverse(int x) {
    char res[20];
    bool flag = false;
    if (x == -2147483648)
        return 0;
    if (x < 0){
        flag = true;
        x = -x;
    }
    sprintf(res, "%d", x);
    int len = strlen(res);
    int size = len / 2;
    len--;
    char temp;
    for (int i = 0; i < size; i++){
        temp = res[i];
        res[i] = res[len - i];
        res[len - i] = temp;
    }
    long long int ans, t;
    sscanf(res, "%lld", &ans);
    t = ans & 0xffffffff80000000;
    if (t){
        return 0;
    }
    if (flag){
        ans = -ans;
    }
    return ans;
}

int firstUniqChar(string s){
    unsigned int letter_cnt [26], first_letter[26];
    bzero(letter_cnt, sizeof(letter_cnt));
    bzero(first_letter, sizeof(first_letter));
    for (size_t i = 0; i < s.size(); i++){
        if (first_letter[s[i] - 'a'] == 0){
            first_letter[s[i] - 'a'] = i;
        }
        letter_cnt[s[i] - 'a']++;
    }
    unsigned int ans = -1;
    for (int i = 0; i < 26; i++){
        if (letter_cnt[i] == 1){
            ans = min(ans, first_letter[i]);    
        }
    }
    return ans;
}

// 若s、 t中字符存在非26个小写字母情况，可将 letters 换成 hash_map
bool isAnagram(string s, string t) {
    if (s.size() != t.size()){
        return false;
    }
    int letters[26];
    bzero(letters, sizeof(letters));
    for (size_t i = 0; i < s.size(); i++){
        letters[s[i] - 'a']++;
        letters[t[i] - 'a']--;        
    }
    for (int i = 0; i < 26; i++){
        if (letters[i] != 0){
            return false;
        }
    }
    return true;
}

bool isPalindrome(string s){
    for (auto i = s.begin(); i != s.end();){
        if ((*i < 'a' || *i > 'z') && 
            (*i < 'A' || *i >'Z') && 
            (*i <'0' || *i >'9')) {
            s.erase(i);
        }else {
            if (*i > 'Z') {
            *i -= 32;
            }
            i++;
        }
    }
    size_t loop = s.size() / 2;
    size_t size = s.size() - 1;
    for (size_t i = 0; i < loop; i++){
        if (s[i] != s[size - i]){
            return false;
        }
    }
    return true;
}

int myAtoi(string str) {
    string num;
    bool flag = false, neg = false;
    for (char c : str){
        if ((c == '-' || c == '+' || (c >= '0' && c<= '9')) && !flag){
            flag = true;
            neg = c == '-';
            if (c != '-' && c != '+'){
                num += c;
            }
            continue;
        }
        if (flag && (c >= '0' && c<= '9')){
            num += c;
        }
        if (!flag && c == ' '){
            continue;
        }
        if (c < '0' || c > '9'){
            break;
        }
    }
    long long int ans = 0;
    size_t size = num.size();
    for (size_t i = 0; i < size; i++){
        ans = ans * 10 + num[i] - '0';
        if (0xffffffff80000000 & ans){
            if (neg){
                return INT32_MIN;
            }else{
                return INT32_MAX;
            }
        }
    }
    if (neg){
        ans = -ans;
    }
    return ans;
}

int strStr(string haystack, string needle) {
    if (needle == ""){
        return 0;
    }
    for (size_t i = 0; i < haystack.size(); i++){
        if (haystack[i] != needle[0]){
            continue;
        }
        if (haystack.size() - i < needle.size()){
            return -1;
        }
        bool flag = true;
        for (size_t j = 0; j < needle.size(); j++){
            if (haystack[i + j] != needle[j]){
                flag = false;
                break;
            }
        }
        if (flag){
            return i;
        }
    }
    return -1;
}

string countAndSay(int n){
    string ans = "1", next;
    for (; n > 1; n--){
        char head = ans[0];
        int cnt = 0;
        for (char c : ans){
            if (c == head){
                cnt++;
            }else{
                next += (cnt + '0');
                next += head;
                head = c;
                cnt = 1;
            }
        }
        next += (cnt + '0');
        next += head;
        ans = next;
        next.clear();
    }
    return ans;

}

string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0){
        return "";
    }
    size_t prefix = strs[0].size();
    for (size_t i = 1; i < strs.size(); i++){
        size_t size = min(strs[i].size(), prefix);
        size_t j = 0;
        for (; j < size; j++){
            if (strs[i][j] != strs[0][j]){
                break;
            }
        }
        prefix = j;
    }
    return strs[0].substr(0, prefix);
}