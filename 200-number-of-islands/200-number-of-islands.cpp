class Solution {
public:
    void DFS(vector<vector<char>>& grid , int i , int j){
        if(i < 0  || j < 0 || i >= grid.size() || j >= grid[0].size()){
            return;
        }
        if(grid[i][j] == '2' || grid[i][j] == '0'){
            return;
        }
        grid[i][j] = '2'; 
        DFS(grid , i + 1 , j);
        DFS(grid , i - 1 , j);
        DFS(grid , i , j + 1);
        DFS(grid , i , j - 1);

    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == '1'){
                    DFS(grid , i , j);
                    ans++;
                }
            }
        }
        return ans;
    }
};