// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void solve(int i , int n , vector<int>&arr , int sum , vector<int>&ans){
        if(i == n){
            return ans.push_back(sum);
        }
        solve(i + 1 , n , arr , sum , ans);
        solve(i + 1 , n , arr , sum + arr[i] , ans);
        return;
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {   vector<int> ans;
        solve(0 , n , arr , 0 ,ans);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends