class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = s.size();
        unordered_map<string , int> word;
        for(int i = 0 ; i < words.size() ; i++){
            word[words[i]]++;
        }
        int wordlen = words[0].size();
        int len = (int)words[0].size() * words.size();
        int left = 0;
        for(int right = len - 1 ; right < n ;){
            unordered_map<string , int> temps;
            for(int i = left ; i <= right ;){
                string currs = s.substr(i , wordlen);
                // cout << currs << endl;
                temps[currs]++;
                i += wordlen;
            }
            int ok = true;
            for(auto &str : word){
                if(temps[str.first] != str.second){
                    ok = false;
                    break;
                }
            }
            if(ok)ans.push_back(left);
            left += 1;
            right += 1;
        }
        return ans;
    }
};