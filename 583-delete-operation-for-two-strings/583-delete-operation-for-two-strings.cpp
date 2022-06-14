class Solution {
public:
    int minDistance(string w1, string w2) {
        int n = w1.size();
        int m = w2.size();
        // vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , 0));
        vector<int> prev(m + 1 , 0) , curr(m + 1 , 0); 
        // for(int i = 1; i < n + 1 ; i++){
        //     dp[i][0] = i;
        // }
        // for(int j = 1 ; j < m + 1 ; j++){
        //     dp[0][j] = j;
        // }
        for(int i = 1 ; i < n + 1 ; i++){
            // curr[0] = 0;
            for(int j = 1 ; j < m + 1; j++){
                if(w1[i - 1] == w2[j - 1]){
                    curr[j] = 1 + prev[j - 1];
                }else{
                    curr[j] = max(prev[j] , curr[j - 1]);
                }
            }
            prev = curr;
        }
        return ((n + m) - 2*prev[m]);
    }
};