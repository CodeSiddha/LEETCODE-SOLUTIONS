class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int , int> fors , fort;
        int n = s.size();
        int m = t.size();
        if(n != m){
            return false;
        }
        for(int i = 0 ; i < n ; i++){
            fors[s[i]]++;
        }
        for(int i = 0 ; i < m ; i++){
            fort[t[i]]++;
        }
        for(auto &x : fors){
            if((fort.count(x.first) == 0) || (fort[x.first] != x.second)){
                return false;
            }
        }
        for(auto &x : fort){
            if((fors.count(x.first) == 0) || (fors[x.first] != x.second)){
                return false;
            }
        }
        return true;
    }
};