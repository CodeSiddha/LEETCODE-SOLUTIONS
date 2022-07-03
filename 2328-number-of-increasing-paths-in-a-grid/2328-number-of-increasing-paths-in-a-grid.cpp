class Solution {
public:
    int dp[1001][1001] , MOD = 1000000007;
    int solve(int i, int j , int &n , int &m , vector<vector<int>>&grid , int prev){
        if(i < 0 || j < 0 || i >= n || j >= m){
            return 0;
        }
        if(grid[i][j] <= prev){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        return dp[i][j] = (1LL + solve(i + 1 , j , n , m , grid , grid[i][j]) + 
                                 solve(i - 1 , j , n , m , grid , grid[i][j]) + 
                                 solve(i , j + 1 , n , m , grid , grid[i][j]) + 
                                 solve(i , j - 1 , n , m , grid , grid[i][j]))%MOD;
    }
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp , -1 , sizeof(dp));
        int res = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
               res = (res + solve(i , j , n , m , grid , 0)%MOD)%MOD; 
            }
        }
        return res;
    }
};