class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        while(lo <= hi){
            
            while(lo < hi && nums[lo] == nums[lo + 1]) lo++;
            while(lo < hi && nums[hi] == nums[hi - 1]) hi--;
            
            int mid = lo + (hi - lo) /2;
            if(nums[mid] == target){
                return true;
            }
            if(nums[mid] >= nums[lo]){
                if(target >= nums[lo] && nums[mid] >= target){
                    hi = mid - 1;
                }else{
                    lo = mid + 1;
                }
            }else{
                if(target <= nums[hi] && target >= nums[mid]){
                    lo = mid + 1;
                }else{
                    hi = mid - 1;
                }
            }
        }
        return false;
    }
};