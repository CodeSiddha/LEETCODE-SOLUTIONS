class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        if(k > n/2){
            for(int i = 1 ; i < n ; i++){
                if(prices[i] > prices[i - 1]){
                    profit += prices[i] - prices[i  - 1];
                }
            }
        }else{
            vector<vector<int>> dp(k + 1 , vector<int>(n + 1 , 0));
            for(int i = 1 ; i < k + 1 ; i++){
                int maxdiff = dp[i - 1][0] - prices[0];
                for(int j = 1 ; j < n + 1 ; j++){
                    dp[i][j] = max(dp[i][j - 1] , prices[j - 1] + maxdiff);
                    maxdiff = max(maxdiff , dp[i - 1][j] - prices[j - 1]);
                }
            }
            profit = dp[k][n];
        }
        return profit;
    }
};