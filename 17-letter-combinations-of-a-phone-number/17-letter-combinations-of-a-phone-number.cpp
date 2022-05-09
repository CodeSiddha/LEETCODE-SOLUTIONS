class Solution {
public:
    const vector<string> key = {"" , "abc", "def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void solve(vector<string>&ans , string digits , string asf){
        if(digits == ""){
            ans.push_back(asf);
            return;
        }
        char currlevel = digits[0];
        string rest = digits.substr(1);
        string options = key[currlevel - '0' - 1];
        for(int i = 0 ; i < options.size() ; i++){
            solve(ans , rest , asf + options[i]);
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        if(digits == ""){
            return {};
        }
        int n = digits.size();
        vector<string> ans;
        solve(ans , digits , "");
        return ans;
    }
};