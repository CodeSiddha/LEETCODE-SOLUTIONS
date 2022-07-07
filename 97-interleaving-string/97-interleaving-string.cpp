class Solution {
public:
    int dp[101][101][201];
    bool solve(int i , int j , int k , int n , int m , int p , string s1 , string s2 , string s3){
        if(i + j > p){
            return false;
        }
        if(i == n && j == m){
            if(k == p)
            return true;
            else return false;
        }
        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }
        if(s1[i] == s3[k] && s2[j] == s3[k]){
            return dp[i][j][k] = (solve(i + 1 , j , k + 1 , n , m , p , s1 , s2 ,s3) || solve(i , j + 1 , k + 1 , n , m , p , s1 , s2 , s3));
        }else if(s1[i] == s3[k]){
            return dp[i][j][k] = solve(i + 1 , j , k + 1 , n , m , p , s1 , s2 ,s3);
        }else if(s2[j] == s3[k]){
            return dp[i][j][k] = solve(i , j + 1 , k + 1 , n , m , p , s1 , s2 , s3);
        }
        return dp[i][j][k] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int p = s3.size();
        memset(dp , -1 , sizeof(dp));
        return solve( 0 , 0 , 0 , n , m , p , s1 , s2 , s3);
    }
};