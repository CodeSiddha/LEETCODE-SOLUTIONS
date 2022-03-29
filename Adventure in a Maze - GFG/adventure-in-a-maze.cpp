// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
vector<int> FindWays(vector<vector<int>>&matrix){
    // Code here
    int n = matrix.size();
    int mod = 1e9+7;
    vector<int> res(2);
    pair<int, int> dp[n][n];
    for(int i=0; i<n;i++)
        for(int j=0; j<n; j++)
            dp[i][j] = {0, matrix[i][j]};
    dp[0][0].first = 1;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n;j++){
            int upPath = 0, leftPath =0, upSum = 0, leftSum = 0;
            if(i>0 && (matrix[i-1][j]==2 or matrix[i-1][j]==3) && dp[i-1][j].first){
                upPath = dp[i-1][j].first;
                upSum = dp[i-1][j].second;
            }
            if(j>0 && (matrix[i][j-1]==1 or matrix[i][j-1]==3) && dp[i][j-1].first){
                leftPath = dp[i][j-1].first;
                leftSum = dp[i][j-1].second;
            }
            dp[i][j] = {max(dp[i][j].first, (leftPath+upPath)%mod), dp[i][j].second + max(leftSum, upSum)%mod};
        }
    }
    
    res[0] = (dp[n-1][n-1].first%mod);
    res[1] = dp[n-1][n-1].first?(dp[n-1][n-1].second%mod):0;
    return res;
}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		vector<int> ans = obj.FindWays(matrix);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends