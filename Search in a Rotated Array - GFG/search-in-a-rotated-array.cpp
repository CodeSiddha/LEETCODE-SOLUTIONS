// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int findMin(int arr[] , int start , int end){
        int n = end;
        if(arr[start] <= arr[end]){
            return start;
        }
        while(start <= end){
            if(arr[start] <= arr[end]){
                return start;
            }
            int mid = start + (end - start) / 2;
            if(arr[mid] < arr[(mid - 1 + n) % n]){
                return mid;
            }else if(arr[mid] > arr[end]){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
    }
    int binarySearch(int arr[] , int start , int end , int key){
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(arr[mid] == key){
                return mid;
            }else if(key > arr[mid]){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return -1;
    }
    int search(int arr[], int start, int end, int key){
    //complete the function here
    //Find min element.
    // binary search on 0 to min - 1 and min to n - 1;
        int Emin = findMin(arr , start , end);
        if(arr[Emin] == key){
            return Emin;
        }
        int ans1 = binarySearch(arr , start , Emin , key);
        int ans2 = binarySearch(arr , Emin + 1 , end , key);
        if(ans1 == -1 && ans2 == -1){
            return -1;
        }else if(ans1 != -1){
            return ans1;
        }else{
            return ans2;
        }
    }
};

// { Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}  // } Driver Code Ends