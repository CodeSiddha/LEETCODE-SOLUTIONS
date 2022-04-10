class Solution {
public:
    int calPoints(vector<string>& s) {
        int n = s.size();
        vector<int> arr;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == "+"){
                int m = arr.size();
                arr.push_back(arr[m - 1] + arr[m - 2]);
            }else if(s[i] == "D"){
                arr.push_back(2*arr.back());
            }else if(s[i] == "C"){
                arr.pop_back();
            }else{
                arr.push_back(stoi(s[i]));
            }
        }
        int ans = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            ans += arr[i];
        }
        return ans;
    }
};