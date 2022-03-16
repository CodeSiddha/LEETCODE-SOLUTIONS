class Solution {
public:
    int INF = INT_MAX - 1;
    int coinChange(vector<int>& coins, int amount) {
        int size = coins.size();
        vector<vector<int>> dp(size + 1 , vector<int>(amount+1));
        for(int j = 0 ; j < amount + 1 ; j++ ){
            dp[0][j] = INF-1;
        }
        for(int i = 1 ; i < size + 1 ; i++ ){
            dp[i][0] = 0;
        }
        
        for(int i = 1 ; i < size+1 ; i++){
            for(int j = 1  ; j < amount + 1 ; j++){
                if(coins[i-1] <= j){
                    dp[i][j] = min(dp[i-1][j] , 1 + dp[i][j - coins[i-1]]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        if(dp[size][amount] == INF-1){
            return -1;
        }
        return dp[size][amount];
    }
};