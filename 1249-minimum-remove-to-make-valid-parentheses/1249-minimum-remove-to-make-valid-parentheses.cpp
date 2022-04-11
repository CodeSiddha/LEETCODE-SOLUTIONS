class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<char> st;
        int f , b ;
        f = b = 0;
        string ans = "";
        for(int i = 0 ; i < n ; i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
               ans += s[i];
            }else if(s[i] == '('){
                ans+= s[i];
                f++;
            }else if(s[i] == ')'){
               if(f != 0){
                   ans += s[i];
                   f--;
               }
            }
        }
        string res = "";
        n = ans.size();
        for(int i = n - 1 ; i >= 0 ; i--){
            if(ans[i] >= 'a' && ans[i] <= 'z'){
               res += ans[i];
            }else if(ans[i] == '('){
                if(b != 0){
                   res += ans[i];
                   b--;
               }
            }else if(ans[i] == ')'){
                res+= ans[i];
                b++;
            }
        }
        reverse(res.begin() , res.end());
        return res;
    }
};