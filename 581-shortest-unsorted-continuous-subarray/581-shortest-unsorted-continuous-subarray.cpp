class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int mx = INT_MIN;
        int mn = INT_MAX;
        int n = nums.size();
        bool flag = false;
        for(int i = 1 ; i < n ; i++){
            // mx = max(mx , nums[i]);
            if(nums[i] < nums[i - 1]){
                flag = true;
            }
            if(flag){
                mn = min(mn , nums[i]);
            }
            
        }
        flag = false;
        for(int i = n - 2; i >= 0 ; i--){
            if(nums[i] > nums[i + 1]){
                flag = true;
            }
            if(flag){
                mx = max(mx , nums[i]);
            }
        }
        int leftBoundary , rightBoundary;
        for(int i = 0 ; i < n ; i++){
            if(mn < nums[i]){
                leftBoundary = i;
                break;
            }
        }
        for(int i = n - 1 ; i >= 0 ; i--){
            if(mx > nums[i]){
                rightBoundary = i;
                break;
            }
        }
        return (rightBoundary - leftBoundary + 1 < 0 ? 0 : rightBoundary - leftBoundary + 1);
    }
};