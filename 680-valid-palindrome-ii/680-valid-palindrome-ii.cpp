class Solution {
public:
    bool check(int i , int j , string s){
        int n = s.size();
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }else{
                i++;
                j--;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        int i = 0;
        int j = n - 1;
        bool deleted = false;
        while(i < j){
            if(s[i] == s[j]){
                i++;
                j--;
            }else if(s[i] != s[j]){
                if(check(i + 1 , j , s)){
                    return true;
                }else if(check(i , j - 1 , s)){
                    return true;
                }
                return false;
            }
        }
        return true;
    }
};