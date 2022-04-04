class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        map<int , int> mpp; 
        vector<vector<int>> dp(n , vector<int>(m));
        
        for(int i = n - 1 ; i >= 0 ; i--){
            for(int j = m - 1 ; j >= 0 ; j--){
                if(i == n - 1 || j == m - 1){
                    dp[i][j] = matrix[i][j];
                }else{
                    if(matrix[i][j] != 0)
                    dp[i][j]  = min(dp[i][j + 1] , min(dp[i + 1][j] , dp[i + 1][j + 1])) + 1;
                }
                mpp[dp[i][j]]++;
            }
        }
        vector<int> help;
        for(auto &x : mpp){
            if(x.first != 0){
                help.push_back(x.second);
            }
        }
        int size = help.size();
        for(int i = size - 2 ; i >= 0 ; i--){
            help[i] += help[i + 1];
        }
        int ans = 0;
        for(int i = 0 ; i < size ; i++){
            ans += help[i];
        }
        return ans;
    }
};