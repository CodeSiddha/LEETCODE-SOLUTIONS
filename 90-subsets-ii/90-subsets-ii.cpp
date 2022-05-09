class Solution {
public:
    void solve(int i , int n , vector<int>&nums ,vector<int> temp, set<vector<int>>&ans){
        if(i == n){
            ans.insert(temp);
            return;
        }
        vector<int> newtemp = temp;
        newtemp.push_back(nums[i]);
        solve(i + 1 , n , nums , temp , ans);        
        solve(i + 1 , n , nums , newtemp , ans);
        return;

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin() , nums.end());
        solve(0 , n , nums, {} , ans);
        vector<vector<int>> result;
        for(auto &x : ans){
            result.push_back(x);
        }
        return result;
    }
};