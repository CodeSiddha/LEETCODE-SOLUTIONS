// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        long long xxory = 0;
        for(int i = 0 ; i < n ; i++){
            xxory = xxory ^ arr[i];
        }
        for(int i = 0 ; i < n ; i++){
            xxory = xxory ^ (i + 1);
        }
    
        int rmsb = xxory & -xxory;
    
        long long x = 0 , y = 0;
    
        for(int i = 0 ; i < n ; i++){
            if((rmsb & arr[i]) == 0){
                x = x ^ arr[i];
            }else{
                y = y ^ arr[i];
            }
        }
        for(int i = 0 ; i < n ; i++){
            if((rmsb & (i + 1)) == 0){
                x = x ^ (i + 1);
            }else{
                y = y ^ (i + 1);
            }
        }
        bool a = false;
        bool b = false;
        for(int i = 0 ; i < n ; i++){
            if(x == arr[i]){
                a = true;
            }
            if(y == arr[i]){
                b = true;
            }
        }
        int *ans = new int[2];
        if(a){
            ans[0] = (int)x;
            ans[1] = (int)y;
        }else{
            ans[0] = (int)y;
            ans[1] = (int)x;
        }
        
        // int ans = {(int)y , (int)x};
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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends