class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        map<char , int> freq;
        for(int i = 0 ; i < n ; i++){
            freq[s[i]]++;
        }
        priority_queue<int> same;
        for(auto &val : freq){
            same.push(val.second);
        }
        int ans = 0;
        while(!same.empty() && same.size() > 1){
            int top = same.top();
            same.pop();
            int nexttop = same.top();
            same.pop();
            if(top == nexttop){
                ans++;
                nexttop--;
                if(nexttop != 0)
                same.push(nexttop);
                same.push(top);
            }else{
                same.push(nexttop);
            }
        }
        return ans;
    }
};