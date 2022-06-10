class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> maxEl;
        int l = 0;
        for(int i = 0 ; i < k - 1 ; i++){
            while(!maxEl.empty() && maxEl.back() < nums[i]) maxEl.pop_back();
            maxEl.push_back(nums[i]);
        }
        for(int r = k - 1 ; r < n ; r++){
                while(!maxEl.empty() && maxEl.back() < nums[r]){
                    maxEl.pop_back();
                }
                maxEl.push_back(nums[r]);
                if(r != k - 1 && maxEl.front() == nums[l]) maxEl.pop_front();
                if(r != k - 1) l++;
                ans.push_back(maxEl.front());
        }
        return ans;
    }
};
