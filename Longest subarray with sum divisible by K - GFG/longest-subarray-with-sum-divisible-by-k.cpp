// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    unordered_map<int,int> rem;
	    rem[0] = -1;
	    int currSum = 0;
	    int ans = 0;
	    for(int i = 0 ; i < n ; i++){
	        currSum += arr[i];
	        int r = currSum % k;
	        if(r < 0){
	            if(rem.count(r + k)){
	                ans = max(ans , i - rem[r + k]);
	            }else{
	                rem[r + k] = i;
	            }
	        }else{
	            if(rem.count(r)){
	                ans = max(ans , i - rem[r]);
	            }else{
	                rem[r] = i;
	            }
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends