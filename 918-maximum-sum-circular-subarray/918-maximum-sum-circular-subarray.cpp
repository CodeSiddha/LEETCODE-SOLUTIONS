class Solution {
public:
    int maxSubarraySumCircular(vector<int>& arr) {
        int n = arr.size();
        int localmax = arr[0];
        int globalmax = arr[0];
        for(int i = 1 ; i < n ; i++){
            if(localmax + arr[i] < arr[i]){
                localmax = arr[i];
            }else{
                localmax += arr[i];
            }
            globalmax = max(globalmax , localmax);
        }
        int localmin = arr[0];
        int globalmin = *min_element(arr.begin() , arr.end());
        for(int i = 1 ; i < n ; i++){
            if(localmin + arr[i] > arr[i]){
                localmin = arr[i];
            }else{
                localmin += arr[i];
            }
            globalmin = min(globalmin , localmin);
        }
        
        int sum = 0;
        for(auto &num : arr){
            sum += num;
        }
        
        if(globalmax > 0)
        return max(globalmax , sum - globalmin);
        return globalmax;
    }
};