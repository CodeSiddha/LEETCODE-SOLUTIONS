class Solution {
public:
    string longestPalindrome(string S) {
       int n = S.size();
       int len = 0;
       string ans = "";
       int mid = 0;
       for(int mid = 0 ; mid < n ; mid++){
           for(int j = 0 ; mid-j >= 0 && mid+j < n ; j++){
                if(S[mid-j] == S[mid + j]){
                    if(( 2*j  + 1) > len){
                    len = 2*j + 1;
                    ans = S.substr(mid-j , len);
                       }
                }else{
                    break;
                }
           }
       }
    //   abba
    //   0123
        for(int mid = 0 ; mid < n ; mid++){
           for(int j = 0 ; (mid-j) >= 0 && (mid+j+1) < n ; j++){
                if(S[mid-j] == S[mid + j + 1]){
                    if(( 2*j  + 2) > len){
                    len = 2*j + 2;
                    ans = S.substr(mid-j , len);
                       }
                }else{
                    break;
                }
           }
       }
       return ans;
    }
};