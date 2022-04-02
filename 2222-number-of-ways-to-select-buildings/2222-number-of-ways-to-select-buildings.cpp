class Solution {
public:
    long long numberOfWays(string s) {
        int n = s.size();
        vector<int> leftzero(n) , leftone(n) , rightzero(n) , rightone(n);
        for(int i = 1 ; i < n ; i++){
            if(s[i - 1] == '0'){
                leftzero[i] = leftzero[i - 1] + 1;
            }else{
                leftzero[i] = leftzero[i - 1];
            }
            if(s[i - 1] == '1'){
                leftone[i] = leftone[i - 1] + 1;
            }else{
                leftone[i] = leftone[i - 1];
            }
        }
        for(int i = n - 2 ; i >= 0 ; i--){
            if(s[i + 1] == '0'){
                rightzero[i] = rightzero[i + 1] + 1;
            }else{
                rightzero[i] = rightzero[i + 1];
            }
            if(s[i + 1] == '1'){
                rightone[i] = rightone[i + 1] + 1;
            }else{
                rightone[i] = rightone[i + 1];
            }
        }
        long long ans = 0;
        for(int i = 1 ; i < n - 1 ; i++){
            if(s[i] == '1'){
                ans += 1ll * (leftzero[i] * rightzero[i]);
            }
            if(s[i] == '0'){
                ans += 1ll * leftone[i] * rightone[i]; 
            }
        }
        return ans;
    }
};