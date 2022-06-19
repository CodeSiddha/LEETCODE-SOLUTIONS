class Solution {
public:
    bool fillDiagonal(vector<vector<char>>&grid , int i , int j , string &str , int &start , int till , int n){
        while(till--){
            grid[i][j] = str[start];
            // cout << str[start];
            start++;
            if(start == n) return false;
            i--;
            j++;
        }
        return true;
    }
    string convert(string s, int numRows) {
        int n = s.size();
        if(numRows == 1){
            return s;
        }
        vector<vector<char>> grid(numRows , vector<char>(1001 , '$'));
        
        int start = 0;
        bool found = false;
        for(int j = 0 ; j < 1001 ; ){
            for(int i = 0 ; i < numRows ; i++){
                
                grid[i][j] = s[start];
                // cout << s[start];
                start++;
                if(start == n){
                    found = true;
                    break;
                }
            }
            if(found) break;
            bool endhere = fillDiagonal(grid , numRows - 2 , j + 1 , s , start , numRows - 2 , n);
            if(!endhere) break;
            j += (numRows - 2) + 1;
            // cout << j << endl;
        }
        string ans = "";
        for(int i = 0 ; i < numRows ; i++){
            for(int j = 0 ; j < 1001 ; j++){
                if(grid[i][j] != '$'){
                    ans += grid[i][j];
                }
            }
        }
        return ans;
    }
};