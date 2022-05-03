class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int> mpp;
        int n = nums.size();
        mpp[0]++;
        int currSum = 0;
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            currSum += nums[i];
            if(mpp.count(currSum - k)){
                ans += mpp[currSum - k];    
            }
            mpp[currSum]++;
        }
        return ans;
    }
};