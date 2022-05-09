class Solution {
public:
    void solve(int i , int n , vector<int>&nums ,vector<int> temp, vector<vector<int>>&ans){
        ans.push_back(temp);
        for(int idx = i ; idx < n ; idx++){
            if(idx != i && nums[idx] == nums[idx - 1]) continue;
            temp.push_back(nums[idx]);
            solve(idx + 1 , n , nums , temp , ans);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin() , nums.end());
        solve(0 , n , nums, {} , ans);
        return ans;
    }
};