class Solution {
public:
    void solve(int i , int k , int n , vector<int> temp , vector<vector<int>>&ans){
        if(k == 0 && n == 0){
            ans.push_back(temp);
            return;
        }
        if(i > 9 || n == 0 || k == 0 || i > n){
            return ;
        }
            temp.push_back(i);
            solve(i + 1 , k - 1 , n - i , temp , ans);
            temp.pop_back();
            solve(i + 1 , k , n , temp , ans);
        
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        solve(1 , k , n, {} , ans);
        return ans;
    }
};