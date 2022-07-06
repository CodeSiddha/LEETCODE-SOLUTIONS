class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int curridx = 1;
        int count = 1;
        for(int i = 1 ; i < n ; i++){
            if(nums[i] == nums[curridx - 1]){
                if(count < 2){
                    nums[curridx] = nums[i];
                    count++;
                    curridx++;
                }
            }else{
                nums[curridx] = nums[i];
                curridx++;
                count = 1;
            }
        }
        return curridx;
    }
};