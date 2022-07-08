class Solution {
public:
    int maxVal = 1000001;
    int dp[21][101][101];
    int solve(int i , int prevColor , int currGroup , int &n , int &m , vector<int>&houses , vector<vector<int>>&cost , int &target){
        if(i == n){
            if(currGroup == target){
                return 0;
            }
            return maxVal;
        }
        if(currGroup > target){
            return maxVal;
        }
        if(dp[prevColor][i][currGroup] != -1){
            return dp[prevColor][i][currGroup];
        }
        if(houses[i] != 0){
            int newCurrGroup = (currGroup + (houses[i] != prevColor));
            return dp[prevColor][i][currGroup] = solve(i + 1 , houses[i] , newCurrGroup , n , m , houses , cost , target);
        }else{
            int minCost = maxVal;
            for(int checkThisColor = 1 ; checkThisColor <= m ; checkThisColor++){
                int newCurrGroup = (currGroup + (checkThisColor != prevColor));
                minCost = min(minCost , cost[i][checkThisColor - 1] + solve(i + 1 , checkThisColor , newCurrGroup , n , m , houses , cost , target));   
            }
            return dp[prevColor][i][currGroup] = minCost;
        }
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int n, int m, int target) {
        //dp[houese][color][groups]
        memset(dp , -1 , sizeof(dp));
        int res = solve(0 , 0 , 0 , n , m , houses , cost , target);
        if(res == maxVal) return -1;
        return res;
    }
};