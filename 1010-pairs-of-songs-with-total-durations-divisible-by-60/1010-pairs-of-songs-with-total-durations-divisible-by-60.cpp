class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        vector<int> freq(60 , 0);
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            int a = time[i] % 60;
            if(a == 0){
                ans += freq[0];
            }else{
                ans += freq[60 - a];
            }
            freq[a]++;
        }
        return ans;
    }
};