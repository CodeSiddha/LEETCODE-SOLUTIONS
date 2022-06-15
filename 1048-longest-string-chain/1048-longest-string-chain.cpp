class Solution {
public:
   
    static bool cmp(string &a , string&b){
        if(a.size() < b.size()) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin() , words.end() , cmp);
        unordered_map<string , int> prechain;
        int ans = 0;
        for(auto str : words){
            for(int i = 0 ; i < str.size() ; i++){
                string pre = str.substr(0 , i) + str.substr(i + 1);
                if(prechain.count(pre)){
                    prechain[str] = max(prechain[str] , prechain[pre] + 1);
                }else{
                    prechain[str] = max(1 , prechain[str]);
                }
            }
            ans = max(ans , prechain[str]);
        }
        return ans;
    }
};