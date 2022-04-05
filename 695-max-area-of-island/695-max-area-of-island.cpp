class Solution {
public:
    void DFS(vector<vector<int>>& grid , int i , int j , int &ans){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()){
            return;
        }
        if(grid[i][j] == 2 || grid[i][j] == 0){
            return;
        }
        if(grid[i][j] == 1)
            ans++;
        grid[i][j] = 2;
        DFS(grid , i + 1 , j , ans);
        DFS(grid , i - 1 , j , ans);
        DFS(grid , i , j + 1 , ans);
        DFS(grid , i , j - 1 , ans);
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int globalans = 0;
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    ans = 0;
                    DFS(grid , i , j , ans);
                    globalans = max(ans , globalans);
                }
            }
        }
        return globalans;
    }
};