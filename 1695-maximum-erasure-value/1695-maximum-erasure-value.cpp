class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int currSum = 0;
        int ans = 0;
        unordered_map<int,int> mpp;
        for(int r = 0 ; r < n ; r++){
            currSum += nums[r];
            if(mpp.count(nums[r]) && mpp[nums[r]] >= 1){
                while(nums[l] != nums[r]){
                    mpp[nums[l]]--;
                    currSum -= nums[l];
                    l++;
                }
                currSum -= nums[l];
                mpp[nums[l]]--;
                l++;
            }
            mpp[nums[r]]++;
            ans = max(currSum , ans);
        }
        return ans;
    }
};