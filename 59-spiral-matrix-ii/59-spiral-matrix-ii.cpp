class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n , vector<int>(n , 0));
        int minRow , minCol;
        minRow = minCol = 0;
        int maxRow , maxCol;
        maxRow = n - 1;
        maxCol = n - 1;
        int dir = 0;
        int num = 1;
        while(minRow <= maxRow && minCol <= maxCol){
            if(dir == 0){
                for(int i = minCol; i <= maxCol ; i++){
                    ans[minRow][i] = num;
                    num++;
                }
                minRow++;
            }else if(dir == 1){
                for(int i = minRow ; i <= maxRow ; i++){
                    ans[i][maxCol] = num;
                    num++;
                }
                maxCol--;
                
            }else if(dir == 2){
                for(int i = maxCol ; i >= minCol ; i--){
                    ans[maxRow][i] = num;
                    num++;
                }
                maxRow--;
                
            }else if(dir == 3){
                for(int i = maxRow ; i >= minRow ; i--){
                    ans[i][minCol] = num;
                    num++;
                }
                minCol++;
            }
            dir = (dir + 1) % 4;
        }
        return ans;
    }
};