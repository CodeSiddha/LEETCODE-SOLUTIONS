class Solution {
public:
    void addFreq(string &ans , int freq , char c){
        for(int i = 0 ; i < freq ; i++){
            ans += c;
        }
    }
    string removeDuplicates(string str, int k) {
        int n = str.size();
        stack<pair<char,int>> s;
        string ans = "";
        for(int i = 0 ; i < n ; i++){
            if(s.empty()){
                s.push({str[i] , 1});
            }else{
                if(str[i] == s.top().first){
                    s.top().second++;
                }else{
                    s.push({str[i] , 1});
                }
                if(s.top().second == k){
                    s.pop();
                }
            }
        }
        while(!s.empty()){
            addFreq(ans , s.top().second , s.top().first);
            s.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};