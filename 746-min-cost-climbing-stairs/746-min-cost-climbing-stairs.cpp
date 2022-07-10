class Solution {
public:
    int dp[10001];
    int solve(int i , int n , vector<int>&cost){
        if(i >= n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        return dp[i] = min(cost[i] + solve(i + 1 , n , cost) , cost[i] + solve(i + 2 , n , cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(dp , -1 , sizeof(dp));
        int f = solve(0 , n , cost);
        int s = solve(1 , n , cost);
        return min(f , s);
    }
};