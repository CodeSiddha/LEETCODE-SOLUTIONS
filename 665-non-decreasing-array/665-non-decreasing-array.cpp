class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        bool ok = true;
        for(int i = 1 ; i < n ; i++){
            if(nums[i - 1] > nums[i]){
                ok = false;
                break;
            }
        }
        if(ok){
            return true;
        }else{
            bool done = false;
            ok = true;
            for(int i = 1 ; i < n - 1 ; i++){
                if(nums[i - 1] > nums[i]){
                   if(nums[i - 1] > nums[ i + 1]){
                       nums[i - 1] = nums[i];
                   }else{
                       nums[i] = nums[i + 1];
                   }
                    done = true;
                    break;
                }
            }
            if(done && nums[n - 2] > nums[n - 1] ){
                return false;
            }else if(nums[n - 2] > nums[n - 1]){
                nums[n - 1] = nums[n - 2];
            }
            for(int i = 1 ; i < n ; i++){
                if(nums[i - 1] > nums[i]){
                ok = false;
                break;
                }
            }
        }
        return (ok ? true : false);
    }
};