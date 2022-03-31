class Solution {
public:
    int solve(int idx , int m  ,  vector<int>&nums, vector<vector<int>>&dp){
        if(idx == nums.size() and m == 0) return 0;
        if(idx == nums.size() or m == 0) return INT_MAX;
            
        if(dp[idx][m] != -1){
            return dp[idx][m];
        }
        int ans = INT_MAX , cur = 0;
        for(int i = idx ; i < nums.size() ; i++){
            cur += nums[i];
            dp[idx][m] = ans = min(ans , max(cur , solve(i + 1 , m - 1 , nums , dp)));
        }
        return dp[idx][m] = ans;
    }
    int splitArray(vector<int>& nums, int m) {
        vector<vector<int>> dp(nums.size() + 1 , vector<int>(m + 1 , -1));
        return solve(0 , m , nums , dp);
    }
};