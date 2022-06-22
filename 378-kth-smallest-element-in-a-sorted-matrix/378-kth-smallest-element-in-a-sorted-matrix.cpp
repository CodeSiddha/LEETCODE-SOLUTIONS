class Solution {
public:
    int cal(vector<vector<int>>& matrix , int val){
        int n = matrix.size();
        int m = matrix[0].size();
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            int start = 0;
            int end = m - 1;
            while(start <= end){
                int mid = start + (end - start)/ 2;
                if(matrix[i][mid] >= val){
                    end = mid - 1;
                }else{
                    start = mid + 1;
                }
            }
            sum += end + 1;
        }
        return sum;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int start = -1e9 + 7;
        int end = 1e9 + 7;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(cal(matrix , mid) >= k){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return end;
    }
};