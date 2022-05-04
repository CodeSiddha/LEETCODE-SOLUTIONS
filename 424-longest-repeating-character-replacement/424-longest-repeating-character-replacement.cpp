class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char,int> Char;
        int left = 0;
        int maxfreq = 0;
        int ans = 0;
        for(int right = 0 ; right < n ; right++){
            Char[s[right]]++;
            if(maxfreq < Char[s[right]]){
                maxfreq = Char[s[right]];
            }
            // maxfreq = max(maxfreq , Char[s[right]]);
            if((right - left + 1) - maxfreq > k){
                Char[s[left]]--;
                left++;
            }
            ans = max(ans , right - left + 1);
        }
        return ans;
    }
};