class Solution {
public:
    // double dPow(double x , int n){
    //     if(n == 0){
    //         return 1;
    //     }
    //     if(n < 0){
    //         n = -n;
    //         x = 1/x;
    //     }
    //     // int cal = dPow(x , n / 2);
    //     if(n % 2 == 0){
    //         return dPow(x*x , n/2);
    //     }else{
    //         return x*dPow(x*x , n/2);
    //     }
    // }
    double myPow(double x, int n) {
        // return dPow(x , n);
        long long m = n;
        if(m < 0){
            m = -1 * m;
        }
        double ans = 1.0;
        while(m){
            if(m % 2){
                ans *= x;
                m = m - 1;
            }else{
                x = x * x;
                m = m/2;
            }
        }
        if(n < 0){
            return (double)1/(double)ans;
        }
        return ans;
    }
};