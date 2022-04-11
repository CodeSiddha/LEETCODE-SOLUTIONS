class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> firstCol(n);        
        for(int time = 0 ; time < k ; time++){
            firstCol[0] = grid[n - 1][m - 1];
            for(int i  = 1 ; i < n ; i++){
                firstCol[i] = grid[i - 1][m - 1];
            }
            for(int i = 0 ; i < n ; i++){
                for(int j = m - 1 ; j > 0 ; j--){
                    grid[i][j] = grid[i][j - 1];
                }
            }
            for(int i = 0 ; i < n ; i++){
                grid[i][0] = firstCol[i];
            }
        }
        return grid;
    }
};