class Solution {
public:
    int findNthDigit(int n) {
        int start = 1;
        int len = 1;
        long range = 9;
        while(n > len * range){
            n -= len *  range;
            len++;
            start *= 10;
            range *= 10;
        }
        start += (n - 1)/len;
        string str = to_string(start);
        return str[(n - 1)%len] - '0';
    }
};