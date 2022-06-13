class Solution {
public:
    int EditDistance(int i , int j , string &w1 , string &w2 , vector<vector<int>>&dp){
        if(i == -1){
            return j + 1;
        }
        if(j == -1){
            return i + 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(w1[i] == w2[j]){
            return dp[i][j] = EditDistance(i - 1 , j - 1 , w1 , w2 , dp);
        }else{
            return dp[i][j] = 1 + min(EditDistance(i - 1 , j , w1 , w2 , dp),
                    min(EditDistance(i , j - 1 , w1 , w2 , dp) , EditDistance(i - 1 , j - 1 , w1 , w2 , dp)));
        }
    }
    int minDistance(string w1, string w2) {
        int n = w1.size();
        int m = w2.size();
        vector<vector<int>>dp(n , vector<int>(m  , -1));
        return EditDistance(n - 1 , m - 1  , w1 , w2 , dp);
    }
};