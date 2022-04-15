class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        
        int n  = arr.size();
        int globalmax =arr[0] ,localmax=arr[0];
        
        for(int i = 1 ; i < n ; i++){
            
            if(arr[i] + localmax < arr[i]){
                localmax = arr[i];      
            }else{
                localmax += arr[i];
            }
            
            globalmax = max(globalmax , localmax);
        }
        return globalmax;
    }
};