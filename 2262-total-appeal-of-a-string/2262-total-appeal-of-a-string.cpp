class Solution {
public:
    long long appealSum(string s) {
        int n = s.size();
        long long res = 0 , prev[26] = {0};
        for(int i = 0 ; i < n ; i++){ // single elemnet se banane waale saari substring i to 0 including i  is i + 1 just update this value in every iteration.
            prev[s[i] - 'a'] = i + 1;
            for(auto &x : prev){
                res += x;
            }
        }
        return res;
    }
};