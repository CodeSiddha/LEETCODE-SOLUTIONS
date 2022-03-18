class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = 1;
        int longest = 1;
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(nums[i] > nums[j])
                dp[i] = max(dp[j] , dp[i]);
            }
            dp[i]++;
            longest = max(longest , dp[i]);
        }
        return longest;
    }
};