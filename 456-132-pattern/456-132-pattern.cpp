class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n < 3){
            return false;
        }//[9,9,9,9,9,1,1,1,10,8,8,8,8,2,2,2,2]
        vector<int> small(n , INT_MAX);
        set<int> front;
        front.insert(nums[0]);
        for(int i = 1 ; i < n ; i++){
            // auto idx = front.lower_bound(nums[i]);
            auto idx = front.begin();
            if(*idx < nums[i]){
                small[i] = *idx;
            }
            front.insert(nums[i]);
            // cout << small[i] << " ";
        }
        vector<int> justlarge(n , INT_MIN);
        set<int> back;
        back.insert(nums[n - 1]);
        for(int i = n - 2 ; i >= 0 ; i--){
            auto idx = back.lower_bound(nums[i]);
            if(idx != back.begin()){
                idx--;
                justlarge[i] = *idx;
            }
            back.insert(nums[i]);
        }
        // for(int i = 0 ; i < n  ; i++){
        //     cout << small[i] << " ";
        // }
        // cout << endl;
        // for(int i = 0 ; i < n  ; i++){
        //     cout << justlarge[i] << " ";
        // }
        // cout << endl;
        for(int i = 0 ; i < n ; i++){
            if(small[i] != INT_MAX && justlarge[i] != INT_MIN){
                if(small[i] < justlarge[i] && justlarge[i] < nums[i]){
                    return true;
                }
            }
        }
        return false;
    }
};