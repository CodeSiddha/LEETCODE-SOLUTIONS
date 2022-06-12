class Solution {
public:
    string rev(string &s){
        int n = s.size();
        for(int i = 0 ; i < n / 2 ; i++){
            swap(s[i] , s[n - i - 1]);
        }
        return s;
    }
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        bool st = false;
        string loc = "";
        for(int i = 0 ; i < n ; i++){
            if(s[i] != ' '){
                st = true;    
            }
            if(st && s[i] != ' '){
                loc += s[i];
            }else if(st && s[i] == ' '){
                loc = rev(loc);
                st = false;
                if(ans == ""){
                    ans += loc;
                }else{
                    ans += " " + loc;
                }
                loc = "";
            }
        }
        if(loc != ""){
            loc = rev(loc);
            if(ans != ""){
                ans += " " + loc;
            }else{
                ans += loc;
            }
        }
        ans = rev(ans);
        return ans;
    }
};