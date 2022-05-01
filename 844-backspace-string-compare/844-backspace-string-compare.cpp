class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<bool> fors(n , false) , fort(m , false);
        int backs = 0;
        for(int i = n - 1 ; i >= 0 ; i--){
            if(s[i] == '#'){
                backs++;
            }
            if(s[i] != '#' && backs){
                fors[i] = true;
                backs--;
            }
        }
        int backt = 0;
        for(int i = m - 1 ; i >= 0 ; i--){
            if(t[i] == '#'){
                backt++;
            }
            if(backt && t[i] != '#'){
                fort[i] = true;
                backt--;
            }
        }
        string news = "" , newt = "";
        for(int i = 0 ; i < n ; i++){
            if(fors[i] == false && s[i] != '#'){
                news += s[i];
            }
        }
        for(int i = 0 ; i < m ; i++){
            if(fort[i] == false && t[i] != '#'){
                newt += t[i];
            }
        }
        return (news == newt);
    }
};