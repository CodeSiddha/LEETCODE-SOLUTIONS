class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 1) return true;
        if(n < 3) return false;
        return fmod((log10(n)/log10(3)) , 1) == 0;
    }
};