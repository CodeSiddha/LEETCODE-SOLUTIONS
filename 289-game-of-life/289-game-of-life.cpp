class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> help(n , vector<int>(m,0));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                int one = 0;
                if(board[i][j] == 0){
                    
                    if(i + 1 < n && j + 1 < m && board[i + 1][j + 1] == 1){
                        one++;
                    }
                    if(i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] == 1){
                        one++;
                    }
                    if(i + 1 < n && board[i + 1][j] == 1){
                        one++;
                    }
                    if(j + 1 < m && board[i][j + 1] == 1){
                        one++;
                    }
                    if(i - 1 >= 0 && board[i - 1][j] == 1){
                        one++;
                    }
                    if(j - 1 >=0 && board[i][j - 1] == 1){
                        one++;
                    }
                    if(i - 1 >= 0 && j + 1 < m && board[i - 1][j + 1] == 1){
                        one++;
                    }
                    if(i + 1 < n && j - 1 >= 0 && board[i + 1][j - 1] == 1){
                        one++;
                    }
                    if(one == 3){
                        help[i][j] = 1;
                    }
                }else{
                    if(i + 1 < n && j + 1 < m && board[i + 1][j + 1] == 1){
                        one++;
                    }
                    if(i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] == 1){
                        one++;
                    }
                    if(i + 1 < n && board[i + 1][j] == 1){
                        one++;
                    }
                    if(j + 1 < m && board[i][j + 1] == 1){
                        one++;
                    }
                    if(i - 1 >= 0 && board[i - 1][j] == 1){
                        one++;
                    }
                    if(j - 1 >=0 && board[i][j - 1] == 1){
                        one++;
                    }
                    if(i - 1 >= 0 && j + 1 < m && board[i - 1][j + 1] == 1){
                        one++;
                    }
                    if(i + 1 < n && j - 1 >= 0 && board[i + 1][j - 1] == 1){
                        one++;
                    }
                    
                    if(one < 2 || one > 3){
                        help[i][j] = 0;
                    }else{
                        help[i][j] = 1;
                    }
                }
            }
        }
        board = help;
    }
};