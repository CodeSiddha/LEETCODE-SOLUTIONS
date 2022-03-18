class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        for(int i = 0 ; i < n ; i++){
            dp[i] = 0;
        }
        dp[0] = 1;
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(nums[i] > nums[j])
                dp[i] = max(dp[j] , dp[i]);
            }
            dp[i]++;
        }
        int longest = 0;
        for(int i = 0 ; i < n ; i++){
            longest = max(longest , dp[i]);
        }
        return longest;
    }
};