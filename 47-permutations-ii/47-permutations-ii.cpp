class Solution {
public:
    void solve(vector<int> nums ,vector<int> temp,set<vector<int>>&per){
        if(nums.size() == 0){
            per.insert(temp);
            return;
        }
        
        for(int i = 0 ; i < nums.size() ; i++){
            int first = nums[i];
            vector<int> rest;
            for(int j = 0 ; j < nums.size() ; j++){
                if(i == j) continue;
                rest.push_back(nums[j]);
            }
            temp.push_back(first);
            solve(rest , temp , per);
            temp.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> per;
        solve(nums ,{},per);
        for(auto &x : per){
            ans.push_back(x);
        }
        return ans;
    }
};