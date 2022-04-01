class Solution {
public:
    bool ok(string s , int k){
        int n = s.size();
        if(s[0] == '0'){
            return false;
        }
        for(int i = 0 ; i < n - 1; i++){
            if(abs((s[i]-'0') - (s[i + 1] - '0')) != k){
                return false;
            }
        }
        return true;
    }
    void solve(int idx , string s , int k , vector<int>& ans , int maxnum ,int n){
        if(s != ""){
            string temp = s;
            if(stoi(temp) > maxnum)
            return;
        }
        if(idx == n){
            // if(ok(s , k)){
            //     ans.push_back(stoi(s));
            // }
            string temp = s;
            ans.push_back(stoi(temp));
            return ;
        }
        char put = '0' , forone = '1';
        for(int i = 0 ; i < 10 ; i++){
            if(idx == 0){
                char add = forone;
                if(forone <= '9')
                forone++;
                else
                return;
                solve(idx + 1 , s + add , k , ans , maxnum , n);
                
            }else{
                if(abs((s[idx - 1] - '0') - (put - '0')) == k){
                char add = put;
                solve(idx + 1 , s + add , k , ans , maxnum , n);
                }
                put++;
            }
        }
        return;
        
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        int maxnum = 0;
        int temp = n;
        while(temp){
            maxnum = maxnum * 10 + 9;
            temp--;
        }
        vector<int> ans;
        string s = "";
        solve(0 , s , k , ans , maxnum, n);
        return ans;
    }
};