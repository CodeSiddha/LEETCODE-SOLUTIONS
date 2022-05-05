class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();        
        vector<vector<string>> ans;
        unordered_map<string , vector<int>> same;
        for(int i = 0 ; i < n ; i++){
            string s = strs[i];
            sort(s.begin() , s.end());
            same[s].push_back(i);
        }
        for(auto &x : same){
            vector<string> temp;
            for(int i = 0 ; i < x.second.size() ; i++){
                temp.push_back(strs[x.second[i]]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};