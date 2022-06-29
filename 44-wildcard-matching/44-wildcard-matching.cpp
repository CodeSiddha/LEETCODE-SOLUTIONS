class Solution {
public:
    int dp[2001][2001];
    bool solve(int i , int  j , string &s1 , string &s2){
        if(i == 0 && j == 0){
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i == 0 ||  j == 0){
            if(i == 0){
                return (s2[j - 1] == '*' && solve(i , j - 1 , s1 , s2));
            }else if(j == 0){
                return false;
            }
        }
        if(s1[i - 1] == s2[j - 1]){
            return dp[i][j] = solve(i - 1 , j - 1 , s1 , s2);
        }else if(s2[j - 1] == '*'){         
            return dp[i][j] = ((solve(i - 1 , j - 1, s1 , s2) || (solve(i - 1 , j , s1 , s2)) || solve(i , j - 1 , s1 , s2)));
        }else if(s2[j - 1] == '?'){
            return dp[i][j] = solve(i - 1 , j - 1 , s1 , s2);
        }else{
            return dp[i][j] = false;
        }
    }
    bool isMatch(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<bool>>dp(n + 1 , vector<bool>(m + 1 , false));
        for(int i = 0 ; i < n + 1 ; i++){
            for(int j = 0 ; j < m + 1 ; j++){
                if(i == 0 && j == 0){
                    dp[i][j] =  true;
                }else if(i == 0 || j == 0){
                    if(i == 0){
                        if(s2[j - 1] == '*')
                            dp[i][j] = dp[i][j - 1];
                    }else if(j == 0){
                        dp[i][j] = false;
                    }
                }else if(s1[i - 1] == s2[j - 1] || s2[j - 1] == '?'){
                    dp[i][j] = dp[i - 1][j - 1];
                }else if(s2[j - 1] == '*'){
                    dp[i][j] = dp[i - 1][j - 1] || (dp[i - 1][j] || dp[i][j - 1]);
                }else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};