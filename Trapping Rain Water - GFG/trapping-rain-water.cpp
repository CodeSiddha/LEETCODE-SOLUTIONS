// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        int leftmax = 0 , rightmax = 0;
        int leftidx = 0 , rightidx = n - 1;
        long long ans = 0;
        while(leftidx < rightidx){
            leftmax = max(leftmax , arr[leftidx]);
            rightmax = max(rightmax , arr[rightidx]);
            if(leftmax < rightmax){
                ans += max(0 , leftmax - arr[leftidx]);
                leftidx++;
            }else{
                ans += max(0 , rightmax - arr[rightidx]);
                rightidx--;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends