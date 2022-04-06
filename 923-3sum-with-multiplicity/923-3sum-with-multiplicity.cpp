class Solution {
public:
    int mod = 1e9 + 7;
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size();
        sort(arr.begin() , arr.end());
        int ans = 0;
        for(int i = 0 ; i < n - 2; i++){
            int lo = i + 1 , hi = n - 1 , sum = target - arr[i];
            int f = 0, s = 0;
            while(lo < hi){
                f = s = 0;
                if(arr[lo] + arr[hi] == sum){
                    if(arr[lo] != arr[hi]){
                        while(lo  < hi && arr[lo] == arr[lo + 1]){
                            lo++;
                            f++;  
                        }
                        while(lo < hi && arr[hi - 1] == arr[hi]){
                            hi--;
                            s++;
                        }
                            hi--;
                            s++;
                            lo++;
                            f++;    
                        ans = ((ans % mod) + (f * s) % mod) % mod;
                    }else{
                        ans += ((hi - lo + 1) * (hi - lo)) / 2;
                        ans %= mod;
                        break;
                    }
                }else if(arr[lo] + arr[hi] < sum){
                    lo++;
                }else{
                    hi--;
                }
            }
        }
        return (ans % mod);
    }
};