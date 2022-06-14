class Solution {
public:
    static bool cmp(string&a , string&b){
        if((int)a.size() < (int)b.size()) return true;
        return false;
    }
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin() , strs.end() , cmp);
        int n = strs.size();
        string lcp = strs[0];
        for(int i = 1 ; i < n ; i++){
            if(lcp == "") break;
            int p = 0;
            while(p < lcp.size() && lcp[p] == strs[i][p]){
                p++;
            }
            lcp = lcp.substr(0 , p);
        }
        return lcp;
    }
};