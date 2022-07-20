class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1) return true;
        if(n < 4) return false;
        return fmod((log10(n)/log10(4)) , 1) == 0 ;
    }
};