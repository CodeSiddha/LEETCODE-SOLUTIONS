class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            while(nums[i] - 1 != i){
                if(nums[i] == nums[nums[i] - 1]){
                    break;
                }
                swap(nums[i] , nums[nums[i] - 1]);
            }
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] - 1 != i){
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};