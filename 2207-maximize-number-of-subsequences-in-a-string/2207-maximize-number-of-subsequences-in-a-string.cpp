class Solution {
public:
    long long cal(string s1 , string s2){
        int n = s1.size();        
        if(s2[0] == s2[1]){
            long long num = 0;
            for(int i = 0 ; i < n ; i++){
                if(s1[i] == s2[0]){
                    num++;
                }
            }
            return 1ll* (((num)*(num) - num)/2);
        }
        long long b = 0;
        long long a = 0;
        for(int i = n - 1 ; i >= 0 ; i--){
            if(s1[i] == s2[1]){
                b++;
            }else if(s1[i] == s2[0]){
                // afterthis.push_back(b);
                a += b;;
            }
        }
        // long long sum = 0;
        // for(int i = 0 ; i < afterthis.size() ; i++){
        //     sum += afterthis[i];
        // }
        return a;
    }
    long long maximumSubsequenceCount(string text, string pattern) {
        int n = text.size();
        vector<int> afterthis;
        int b = 0;
        int a = 0;
        long long ans1 = cal(text + pattern[0] , pattern);        
        long long ans2 = cal(text + pattern[1] , pattern);
        long long ans3 = cal(pattern[0] + text , pattern);
        long long ans4 = cal(pattern[1] + text , pattern);
        return max({ans1 , ans2 , ans3 , ans4});
    }
};