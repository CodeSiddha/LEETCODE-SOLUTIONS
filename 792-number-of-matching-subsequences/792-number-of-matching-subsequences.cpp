class Solution {
public:

    int numMatchingSubseq(string s, vector<string>& words) {
        int n = words.size();
        vector<vector<int>> pos(26);
        for(int i = 0 ; i < s.size() ; i++){
            pos[s[i] - 'a'].push_back(i);
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            bool found = true;
            int x = -1;
            for(int j = 0 ; j < words[i].size() ; j++){
                char ch = words[i][j];
                auto idx = upper_bound(pos[ch -'a'].begin() , pos[ch - 'a'].end() , x);
                if(idx == pos[ch - 'a'].end()){
                    found = false;
                    break;
                }
                x = *idx;
            }
            if(found)ans++;
        }
        return ans;
    }
};