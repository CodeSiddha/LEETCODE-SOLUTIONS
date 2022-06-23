class Solution {
public:
    bool dfs(int i,int j,vector<vector<char>>&board , string &word , vector<vector<bool>>&visited , int idx){
        if(idx == word.size()){
            return true;
        }
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()){
            return false;
        }
        if(board[i][j] != word[idx]){
            return false;
        }
        if(visited[i][j] == true)
            return false;
        visited[i][j] = true;
        idx++;
        if(dfs(i + 1 , j , board , word , visited , idx) || 
           dfs(i - 1 , j , board , word , visited , idx) ||
           dfs(i , j + 1 , board , word , visited , idx) ||
           dfs(i , j - 1 , board , word , visited , idx)){
            return true;
        }
        idx--;
        visited[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n , vector<bool>(m , false));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == word[0]){
                    if(dfs(i , j , board , word ,  visited , 0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};