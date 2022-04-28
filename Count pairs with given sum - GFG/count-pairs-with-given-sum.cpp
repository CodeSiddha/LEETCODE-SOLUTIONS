// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        unordered_map<int ,int> mpp;
        for(int i = 0 ; i < n ; i++){
            mpp[arr[i]]++;
        }
        int ans = 0;
        for(auto &x : mpp){
            int want = k - x.first;
            if(mpp.count(want)){
                if(mpp[want] && want == x.first){
                    ans += ((x.second) * (x.second - 1)) / 2;
                    mpp[want] = 0;
                }else if(mpp[want] > 0){
                    ans += mpp[want] * mpp[x.first];
                    mpp[want] = 0;
                    mpp[x.first] = 0;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}  // } Driver Code Ends