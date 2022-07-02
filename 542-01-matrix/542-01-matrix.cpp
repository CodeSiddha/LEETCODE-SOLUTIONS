class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dis(n , vector<int>(m , INT_MAX));
        queue<pair<int,int>> que;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 0){
                    que.push({i , j});
                    dis[i][j] = 0;
                }
            }
        }
        int dir[4][2] = {{1,0},{0,-1},{-1,0},{0,1}};
        
        while(!que.empty()){
            auto top = que.front();
            que.pop();
            for(int i = 0 ; i < 4 ; i++){
                int old_r = top.first;
                int old_c = top.second;
                int new_r = old_r + dir[i][0];
                int new_c = old_c + dir[i][1];
                if(new_r >= 0 && new_c >= 0 && new_r < n && new_c < m){
                    if(dis[new_r][new_c] > dis[old_r][old_c] + 1){
                        dis[new_r][new_c] = dis[old_r][old_c] + 1;
                        que.push({new_r , new_c});
                    }
                }
            }
        }
        return dis;
    }
};