class Solution {
public:
   
    void DFS(vector<vector<int>>&grid , int i , int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()){
            return;
        }
        if(grid[i][j] == 0){
            return;
        }
        grid[i][j] = 0;
        DFS(grid , i + 1 , j);        
        DFS(grid , i - 1 , j);
        DFS(grid , i , j + 1);
        DFS(grid , i , j - 1);
        return;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid2[i][j] == 1 && grid1[i][j] == 0){
                    DFS(grid2 , i , j);
                }
            }
        }
        int countIsland = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid2[i][j] == 1){
                    DFS(grid2 , i , j);
                    countIsland++;
                }
            }
        }
        return countIsland;
    }
};