// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    void nsr(int arr[] , int n , vector<int>&ans){
        // vector<int> ans(n , n);
        stack<pair<int,int>> st;
        for(int i = n - 1 ; i >= 0 ; i--){
            if(st.empty()){
                st.push({arr[i] , i});
            }else{
                while(!st.empty() && st.top().first >= arr[i]){
                    st.pop();
                }
                if(!st.empty()){
                    ans[i] = st.top().second;
                }
                st.push({arr[i] , i});
            }
        }
        return;
    }
    void nsl(int arr[] , int n , vector<int>&ans){
        // vector<int> ans(n , 0);
        stack<pair<int,int>> st;
        for(int i = 0 ; i < n ; i++){
            if(st.empty()){
                st.push({arr[i] , i});
            }else{
                while(!st.empty() && st.top().first >= arr[i]){
                    st.pop();
                }
                if(!st.empty()){
                    ans[i] = st.top().second;
                }
                st.push({arr[i] , i});
            }
        }
        return;
    }
    vector <int> maxOfMin(int arr[], int n)
    {
        vector<int> rightns(n , n);
        vector<int> leftns(n , -1);
        nsr(arr , n , rightns);
        nsl(arr , n , leftns);
        vector<int> span(n);
        for(int i = 0 ; i < n ; i++){
            span[i] = rightns[i] - leftns[i] - 1;
        }
        vector<int> ans(n);
        for(int i = n - 1 ; i >= 0 ; i--){
            if(ans[span[i] - 1] < arr[i]){
                ans[span[i] - 1] = arr[i];
            }
        }
        for(int i = n - 2; i >= 0 ; i--){
            ans[i] = max(ans[i] , ans[i + 1]);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends