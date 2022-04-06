class Solution {
public:
    void invalid(vector<vector<int>>&grid , int i , int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()){
            return ;
        }
        if(grid[i][j] == 0){
            return;
        }
        grid[i][j] = 0;
        invalid(grid , i + 1 , j);        \
        invalid(grid , i - 1 , j);
        invalid(grid , i , j - 1);
        invalid(grid , i , j + 1);
        return;

    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if((i == 0 || j == 0 || i == n - 1 || j == m -1) && grid[i][j] == 1){
                    invalid(grid , i , j);
                }
            }
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    ans++;
                }
            }
        }
        return ans;
    }
};