class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n , INT_MAX);
        dp[n - 1] = 0;
        for(int i = n - 2 ; i >= 0 ; i--){
            if(nums[i] == 0){
                dp[i] = INT_MAX;
            }else{
                int mn = INT_MAX;
                for(int j = i + 1 ; j < (i + 1 + nums[i]) ; j++){
                    if(j < n){
                        mn = min(dp[j] , mn);
                    }else{
                        break;
                    }
                }
                if(mn != INT_MAX)
                dp[i] = mn + 1;
            }
            
        }
        return dp[0];
    }
};