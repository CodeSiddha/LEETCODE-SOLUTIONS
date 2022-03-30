class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = -1;
        for(int i = 0 ; i < n ; i++){
            if(matrix[i][m - 1] == target){
                return true;
            }else if(matrix[i][m - 1] > target){
                row = i;
                break;
            }
        }
        if(row == -1)
            return false;
        int starti = row;
        int startj = 0;
        int endi = row;
        int endj = m - 1;
        while(startj <= endj){
            int midj = (startj + endj) >> 1;
            if(matrix[row][midj] == target){
                return true;
            }else if(matrix[row][midj] > target){
                endj = midj - 1;
            }else{
                startj = midj + 1;
            }
        }
        return false;
    }
};