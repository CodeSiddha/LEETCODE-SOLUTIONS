class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        int minRow , minCol;
        minRow = minCol = 0;
        int maxRow , maxCol;
        maxRow = n - 1;
        maxCol = m - 1;
        int dir = 0;
        while(minRow <= maxRow && minCol <= maxCol){
            if(dir == 0){
                for(int i = minCol; i <= maxCol ; i++){
                    ans.push_back(matrix[minRow][i]);
                }
                minRow++;
            }else if(dir == 1){
                for(int i = minRow ; i <= maxRow ; i++){
                    ans.push_back(matrix[i][maxCol]);
                }
                maxCol--;
                
            }else if(dir == 2){
                for(int i = maxCol ; i >= minCol ; i--){
                    ans.push_back(matrix[maxRow][i]);
                }
                maxRow--;
                
            }else if(dir == 3){
                for(int i = maxRow ; i >= minRow ; i--){
                    ans.push_back(matrix[i][minCol]);
                }
                minCol++;
            }
            dir = (dir + 1) % 4;
        }
        return ans;
    }
};