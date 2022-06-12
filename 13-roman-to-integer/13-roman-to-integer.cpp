class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        unordered_map<char , int> roman;
        roman['I'] = 1;        
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;
        vector<int> nums;
        nums.push_back(roman[s[n - 1]]);
        for(int i = n - 2 ; i >= 0 ; i--){
            if(roman[s[i]] < nums.back()){
                nums.back() = nums.back() - roman[s[i]];
            }else{
                nums.push_back(roman[s[i]]);
            }
        }
        int ans = 0;
        for(int i = 0 ; i < (int)nums.size() ; i++){
            ans += nums[i];
        }
        return ans;
    }
};