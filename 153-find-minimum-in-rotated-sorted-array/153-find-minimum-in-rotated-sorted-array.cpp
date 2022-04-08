class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int minans = INT_MAX;
        if(n == 1){
            return nums[0];
        }
        if(nums[0] < nums[n - 1]){
            return nums[0];
        }
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(nums[0] > nums[mid]){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return nums[start];
    }
};