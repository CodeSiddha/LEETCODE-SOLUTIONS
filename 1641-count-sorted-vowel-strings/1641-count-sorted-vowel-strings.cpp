class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5);
        for(int i = 0 ; i < 5 ; i++){
            dp[i] = 1;
        }
        int m = n - 1;
        while(m--){
            for(int i = 1 ; i < 5 ; i++){
                dp[i] = dp[i] + dp[i - 1];
            }
        }
        int ans = 0;
        for(int i = 0 ; i < 5 ; i++){
            ans += dp[i];
        }
        return ans;
    }
};