class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        vector<pair<int ,int>> order;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0 ; i < n ; i++){
            int one = 0;
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 1)
                    one++;
            }
            order.push_back({one , i});
        }
        sort(order.begin() , order.end());
        for(int i = 0 ; i < k ; i++){
            ans.push_back(order[i].second);
        }
        return ans;
    }
};