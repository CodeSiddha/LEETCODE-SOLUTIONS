class Solution {
public:
    int minPartitions(string s) {
        int n = s.size();
        int maxchar = 0;
        for(int i = 0 ; i < n ; i++){
            if(maxchar < s[i] - '0'){
                maxchar = s[i] - '0';
            }
        }
        return maxchar;
    }
};