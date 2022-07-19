class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> temp(1 , 1);
        ans.push_back(temp);
        for(int i = 2 ; i <= numRows ; i++){
            temp.resize(i , 1);
            for(int j = 1 ; j < i - 1 ; j++){
                temp[j] = ans[i - 2][j - 1] + ans[i - 2][j]; // indexing of i is 0...n if i = 2 then ans[1] is valid index.
            }
            ans.push_back(temp);
        }
        return ans;
    }
};