class Solution {
public:
    int MOD = 1000000007;
    int dp[51][51][51];
    int solve(int i , int  j , int n , int m , int move){
        if(i < 0 || j < 0 || i >= n || j >= m) return 1;
        if(move == 0) return 0;
        if(dp[i][j][move] != -1){
            return dp[i][j][move]% MOD;
        }
        return dp[i][j][move] = (1ll * solve(i + 1 , j , n , m , move - 1)% MOD + 1ll * solve(i - 1 , j , n , m , move - 1)% MOD + 1ll * solve(i , j + 1 , n , m , move - 1)% MOD + 1ll * solve(i , j - 1 , n , m , move - 1)% MOD) % MOD;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp , -1 ,sizeof(dp));
        return solve(startRow , startColumn , m , n , maxMove);
    }
};