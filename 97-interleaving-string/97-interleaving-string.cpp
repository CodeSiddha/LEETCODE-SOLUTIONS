class Solution {
public:
    int dp[101][101];
    bool solve(int i , int j , int n , int m , string s1 , string s2 , string s3){ // i + j == k
        if(i + j > s3.size()){
            return false;
        }
        if(i == n && j == m){
            if(i + j == s3.size())
            return true;
            else return false;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s1[i] == s3[i + j] && s2[j] == s3[i + j]){
            return dp[i][j] = (solve(i + 1 , j , n , m , s1 , s2 ,s3) || solve(i , j + 1 , n , m , s1 , s2 , s3));
        }else if(s1[i] == s3[i + j]){
            return dp[i][j] = solve(i + 1 , j , n , m , s1 , s2 ,s3);
        }else if(s2[j] == s3[i + j]){
            return dp[i][j] = solve(i , j + 1 , n , m , s1 , s2 , s3);
        }
        return dp[i][j] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int p = s3.size();
        memset(dp , -1 , sizeof(dp));
        return solve( 0 , 0 , n , m , s1 , s2 , s3);
    }
};