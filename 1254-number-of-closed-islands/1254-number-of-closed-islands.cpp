class Solution {
public:
    void Removezero(vector<vector<int>>&grid , int i  , int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()){
            return;
        }
        if(grid[i][j] == 1){
            return;
        }
        grid[i][j] = 1;
        Removezero(grid , i + 1 , j );        
        Removezero(grid , i - 1 , j );
        Removezero(grid , i , j + 1 );
        Removezero(grid , i , j - 1 );
        return;
    }
    void DFS(vector<vector<int>>&grid , int i  , int j ){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ){
            return;
        }
        if(grid[i][j] == 2 || grid[i][j] == 1){
            return;
        }
        
        grid[i][j] = 2;
        Removezero(grid , i + 1 , j );        
        Removezero(grid , i - 1 , j );
        Removezero(grid , i , j + 1 );
        Removezero(grid , i , j - 1 );
        return;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
    
        for(int i = 0 ; i < n  ; i++){
            for(int j = 0 ; j < m ; j++){
                if((i == n - 1 || j == m - 1 || i == 0 || j == 0) && grid[i][j] == 0){
                    Removezero(grid , i , j);
                }
            }
        }
        int ans = 0;
        // vector<vector<bool>> visited(n , vetor<bool>(m , false));
        for(int i = 1 ; i < n - 1 ; i++){
            for(int j = 1 ; j < m - 1; j++){
                if(grid[i][j] == 0){
                    DFS(grid , i , j);
                    ans++;
                }
            }
        }
        return ans;
    }
};