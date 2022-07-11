class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // abcab ab
        // 
        vector<int> ans;
        int n = s.size();
        unordered_map<char , int> forp;
        for(int i = 0 ; i < p.size() ; i++){
            forp[p[i]]++;
        }
        unordered_map<char , int> fors;
        int left = 0;
        for(int right = 0 ; right < n ; right++){
            fors[s[right]]++;
            if(right - left + 1 > p.size()){
                fors[s[left]]--;
                left++;
            }
            if(right - left + 1 == p.size()){
                bool found = true;
                for(auto forpit : forp){
                    if(fors[forpit.first] != forpit.second){
                        found = false;
                        break;
                    }
                }
                if(found) ans.push_back(right - p.size() + 1);
            }
        }
        return ans;
    }
};