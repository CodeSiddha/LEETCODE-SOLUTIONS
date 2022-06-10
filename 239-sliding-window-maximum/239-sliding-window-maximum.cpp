class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        multiset<int> maxEl;
        int l = 0;
        for(int r = 0 ; r < n; r++){
            maxEl.insert(nums[r]);
            if(r - l + 1 > k){
                maxEl.erase(maxEl.find(nums[l]));
                l++;
            }
            if(r - l + 1 == k){
                auto it = maxEl.end();
                --it;
                ans.push_back(*it);    
            } 
        }
        return ans;
    }
};