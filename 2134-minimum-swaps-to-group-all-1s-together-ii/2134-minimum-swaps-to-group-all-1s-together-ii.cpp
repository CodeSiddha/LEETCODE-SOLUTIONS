class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 1) ones++;
        }
        int maxOnes = 0;
        int locOnes = 0;
        int l = 0;
        for(int r = 0 ; r < 2 * n ; r++){
            if(nums[r % n] == 1) locOnes++;
            if(r - l + 1 > ones){
                locOnes -= nums[l];
                l = ((l + 1) % n);
            }
            if(r - l + 1 == ones) maxOnes = max(maxOnes , locOnes); 
        }
        return ones - maxOnes;
    }
};