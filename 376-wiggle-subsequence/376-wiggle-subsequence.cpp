class Solution {
public:
    int dp[1001][1001];
    int solve(int i , int n , vector<int>&nums , int idx){
        if(i == n){
            return 0;
        }
        if(dp[i][idx] != -1){
            return dp[i][idx];
        }
        if(i == idx){
            return dp[i][idx] = max(1 + solve(i + 1 , n , nums , i) , solve(i + 1 , n , nums , i + 1));
        }else{
            if((nums[i] < 0 && nums[idx] > 0) || (nums[i] > 0 && nums[idx] < 0)){
                return dp[i][idx] = max(1 + solve(i + 1 , n , nums , i) , solve(i + 1 , n , nums , idx));
            }else{
                return dp[i][idx] = solve(i + 1 , n , nums , idx);
            }
        }
    }
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 1;
        }
        if(n == 2){
            if(nums[0] != nums[1]){
                return 2;
            }else{
                return 1;
            }
        }
        bool same = true;
        for(int i = 1 ; i < n ; i++){
            if(nums[i] != nums[i - 1]){
                same = false;
            }
        }
        if(same){
            return 1;
        }
        vector<int> diff;
        memset(dp , -1 , sizeof(dp));
        for(int i = 1 ; i < n ; i++){
            diff.push_back(nums[i] - nums[i - 1]);
        }
        int ans = 1 + solve(0 , diff.size() , diff , 0);
        return ans;
    }
};