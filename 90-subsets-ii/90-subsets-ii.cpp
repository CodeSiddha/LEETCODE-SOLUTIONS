class Solution {
public:
    void solve(int i , int n , vector<int>&nums ,vector<int>&temp, vector<vector<int>>&ans){
        ans.push_back(temp);
        for(int idx = i ; idx < n ; idx++){
            temp.push_back(nums[idx]);
            solve(idx + 1 , n , nums , temp , ans);
            temp.pop_back();
            while(idx + 1  < nums.size() && nums[idx] == nums[idx + 1]) idx++;

        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<int> temp;
        solve(0 , n , nums, temp , ans);
        return ans;
    }
};