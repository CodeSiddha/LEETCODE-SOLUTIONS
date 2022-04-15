class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        int imin = arr[0];
        int imax = arr[0];
        int ans = arr[0];
        for(int i = 1 ; i < n ; i++){
            if(arr[i] < 0){
                swap(imax , imin);
            }
            imax = max(arr[i] , imax * arr[i]);
            imin = min(arr[i] , imin * arr[i]);
            
            ans = max(imax , ans);
        }
        return ans;
    }
};