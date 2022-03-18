class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> store;
        store.push_back(nums[0]);
    
        for(int i = 1 ; i < n ; i++){
            if(nums[i] > store.back()){
                store.push_back(nums[i]);
            }else{
                int idx = lower_bound(store.begin() , store.end() , nums[i]) - store.begin();
                store[idx] = nums[i];
            }
        }
        return (int)store.size();
    }
};