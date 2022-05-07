class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i < n - 3; i++){
            if(i == 0 || (i > 0 && nums[i] != nums[i - 1])){
                int outer = nums[i];
                for(int j = (i + 1) ; j < n - 2; j++){
                    if(j == (i + 1) || (j > (i + 1) && nums[j] != nums[j - 1])){
                        int lo = j + 1;
                        int hi = n - 1;
                        int find = target - outer - nums[j];
                        while(lo < hi){
                            if(nums[lo] + nums[hi] == find){
                                ans.push_back({outer , nums[j] , nums[lo] , nums[hi]});
                                while(lo < hi && nums[lo] == nums[lo + 1]) lo++;
                                while(lo < hi && nums[hi] == nums[hi - 1]) hi--;
                                lo++;
                                hi--;
                            }else if(nums[lo] + nums[hi] > find){
                                hi--;
                            }else{
                                lo++;
                            }
                        }   
                    }
                }    
            }
        }
        return ans;
    }
};