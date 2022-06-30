class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int total = 0;
        sort(nums.begin() , nums.end());
        int val = nums[n/2];
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            ans += abs(nums[i] - val);
        }
        return ans;
    }
};