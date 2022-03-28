class Solution {
    private:
    vector<pair<string , int>> num = {{"zero",0} , {"one" , 1} , {"two",2} , {"three",3} , {"four",4} , {"five",5} , {"six",6} , {"seven",7} , {"eight",8} , {"nine",9}}; 
public:
    string originalDigits(string s) {
        unordered_map<int,int> mpp;
        string ans = "";
        vector<int> num(10);
        vector<int> allChar((int)('z') + 1 , 0);
        for(auto x : s){
            mpp[x - 'a']++;
        }
        num[0] = mpp['z' - 'a'];
        num[4] = mpp['u' - 'a'];
        num[2] = mpp['w' - 'a'];
        num[1] = mpp['o' - 'a'] - num[2] - num[4] - num[0];
        num[8] = mpp['g' - 'a'];
        num[3] = mpp['t' - 'a'] - num[2] - num[8];
        num[5] = mpp['f' - 'a'] - num[4];
        num[6] = mpp['x' - 'a'];
        num[7] = mpp['s' - 'a'] - num[6];
        num[9] = mpp['i' - 'a'] - num[6] - num[8] - num[5];
        for(int i = 0 ; i < 10 ; i++){
            ans += string(num[i] , '0' + i);
        }
        return ans;
    }
};