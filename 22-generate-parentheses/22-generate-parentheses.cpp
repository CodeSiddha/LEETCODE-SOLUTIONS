class Solution {
public:
    void solve(int open , int close , string asf , vector<string>&ans){
        if(open == 0 && close == 0){
            ans.push_back(asf);
            return;
        }
        if(open == 0 && close > 0){
            solve(open , close - 1 , asf + ")" , ans);
        }else if(open == close){
            solve(open - 1 , close , asf + "(" , ans);
        }else if(open < close){
            solve(open - 1 , close , asf + "(" , ans);
            solve(open , close - 1 , asf + ")" , ans);
        }else{
            return;
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n , n , "" , ans);
        return ans;
    }
};