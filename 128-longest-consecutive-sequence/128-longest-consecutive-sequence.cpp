class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mpp;
        for(int i = 0 ; i < n ; i++){
            mpp[nums[i]]++;
        }
        int glen = 0;
        int llen = 0;
        int currNum = 1e9 + 1;
        int prev = 1e9 + 1;
        for(auto &x : mpp){
            if(prev == 1e9 + 1){
                prev = x.first;
                llen = 1;
            }else{
                if(x.first - 1 == prev){
                    llen++;
                    prev = x.first;
                }else{
                    llen = 1;
                    prev = x.first;
                }
            }
            glen = max(glen , llen);
        }
        return glen;
    }
};