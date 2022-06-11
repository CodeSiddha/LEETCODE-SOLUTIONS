class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
        }
        int l = 0;
        int r = 0;
        long long want = sum - x;
        if(x > sum){
            return -1;
        }
        if(sum == x){
            return n;
        }
        long long currSum = 0;
        int maxlen = 0;
        for( ; r < n ; r++){
            currSum += nums[r];
            while(currSum > want){
                currSum -= nums[l];
                l++;
            }
            if(currSum == want){
                maxlen = max(maxlen , r - l + 1);
            }
        }
        if(maxlen == 0){
            return -1;
        }
        return (n - maxlen);
    }
};