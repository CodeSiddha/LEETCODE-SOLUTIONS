class Solution {
private:
    vector<unordered_map<char,int>> freq;
public:
    int dp[1001][1001];
    int solve(int i , int n , vector<string>&arr , int pred){
        if(i == n){
            return 0;
        }
        if(dp[i][pred] != -1){
            return dp[i][pred];
        }
        if(i == pred){
            return dp[i][pred] = max(1 + solve(i + 1 , n , arr , i) , solve(i + 1 , n , arr , i + 1));
        }else{
            if(arr[pred].size() + 1 == arr[i].size()){
                string s = arr[i];
                bool found = false;
                for(int j = 0 ; j < (int)s.size() ; j++){
                    string pres = s.substr(0 , j) + s.substr(j + 1);
                    if(pres == arr[pred]){
                        found = true;
                        break;
                    }
                }
                if(found){
                    return dp[i][pred] = max(1 + solve(i + 1 , n , arr , i) , solve(i + 1 , n , arr , pred));
                }else{
                    return dp[i][pred] = solve(i + 1 , n , arr , pred);
                }
            }else{
                return dp[i][pred] = solve(i + 1 , n , arr , pred);
            }
        }
    }
    static bool cmp(string &a , string&b){
        if(a.size() < b.size()) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin() , words.end() , cmp);
        // for(int i = 0 ; i < n ; i++){
        //     string str = words[i];
        //     unordered_map<char , int> Sfreq;
        //     for(int j = 0 ; j < (int) str.size() ; j++){
        //         Sfreq[str[j]] = j;
        //     }
        //     freq.push_back(Sfreq);
        // }
        memset(dp , -1 , sizeof(dp));
        return solve(0 , n , words , 0 );
    }
};