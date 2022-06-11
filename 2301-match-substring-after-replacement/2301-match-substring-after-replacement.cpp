class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        // map<char , char> mpp;
        set<pair<char , char>> st;
        for(int i = 0 ; i < mappings.size() ; i++){
                st.insert({mappings[i][0] , mappings[i][1]});
        }
        int n = s.size();
        int m = sub.size();
        vector<string> substrs;
        for(int i = 0 ; i < n - m + 1 ; i++){
            substrs.push_back(s.substr(i,m));
            // cout << substrs.back() << endl;
        }
        for(int i = 0 ; i <(int)substrs.size() ; i++){
            string str = substrs[i];
            string ssub = sub;
            for(int j = 0 ; j < str.size() ; j++){
                if(ssub[j] != str[j]){
                    if(st.find({ssub[j] , str[j]}) != st.end()){
                        ssub[j] = str[j];
                    }else{
                        break;
                    }
                }
            }
            // cout << sub << endl;
            if(str == ssub){
                return true;
            }
        }
        
        return false;
    }
};