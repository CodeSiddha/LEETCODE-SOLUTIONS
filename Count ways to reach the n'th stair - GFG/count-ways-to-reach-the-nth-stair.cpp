// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int dp[10001];
    int MOD = 1e9 + 7;
    int solve(int n , int &ans){
        if(n < 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n] % MOD;
        }
        if(n == 0){
            return 1;
        }
        return dp[n] = (solve(n - 1 , ans) + solve(n - 2 , ans)) % MOD;
    }
    int countWays(int n)
    {
        memset(dp , -1 , sizeof(dp));
        int ans = 0;
        return solve(n , ans);
    }
};



// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}
  // } Driver Code Ends