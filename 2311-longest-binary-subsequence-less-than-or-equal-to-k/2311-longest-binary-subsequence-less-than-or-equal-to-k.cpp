class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int val = 0;
        int pow = 1;
        int one = 0;
        for(int i = n - 1 ; i >= 0 && val + pow <= k ; i--){
            if(s[i] == '1'){
                one++;
                val += pow;
            }
            pow <<= 1;
        }
        int zero = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '0') zero++;
        }
        return zero + one;
    }
};