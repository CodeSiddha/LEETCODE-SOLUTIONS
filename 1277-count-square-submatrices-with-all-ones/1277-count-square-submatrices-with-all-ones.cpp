class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(n , vector<int>(m));
        
        for(int i = n - 1 ; i >= 0 ; i--){
            for(int j = m - 1 ; j >= 0 ; j--){
                if(i == n - 1 || j == m - 1){
                    dp[i][j] = matrix[i][j];
                }else{
                    if(matrix[i][j] != 0)
                    dp[i][j]  = min(dp[i][j + 1] , min(dp[i + 1][j] , dp[i + 1][j + 1])) + 1;
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
};