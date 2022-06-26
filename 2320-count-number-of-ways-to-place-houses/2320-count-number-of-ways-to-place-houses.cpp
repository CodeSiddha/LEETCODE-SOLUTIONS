int MOD = 1e9 + 7;
class Solution {
public:
    int countHousePlacements(int n) {
        int last = 1;
        int lastlast = 1;
        int ans = 0;
        for(int i = 1; i <= n ; i++){
            ans = (last%MOD + lastlast%MOD)%MOD;
            lastlast = last;
            last = ans;
        }
        return (1ll*ans%MOD*ans%MOD)%MOD;
    }
};