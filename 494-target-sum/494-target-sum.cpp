class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int diff) {
        int n  = arr.size();
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += arr[i];
        }
        if((diff+sum) % 2 == 1 || diff > sum || diff < -sum) return 0;
        int s1 = (diff + sum)/2;
        
        vector<vector<int>> dp(n+1 , vector<int>(s1 + 1 , 0 ));
        dp[0][0] = 1;
        
        for(int i = 1 ; i < n + 1 ; i++){
            for(int j = 0 ; j < s1 + 1 ; j++){
                if(arr[i-1] <= j){
                dp[i][j] = (dp[i-1][j] + dp[i-1][j - arr[i-1]]);
            }else{
                dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][s1];
    }
};