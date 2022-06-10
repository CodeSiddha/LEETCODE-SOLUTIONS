class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dir[][2] = {{0 , 1} , {1 , 0} , {-1 , 0} , {0 , -1}};
        queue<pair<int , pair<int,int>>> rotten;
        int one = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    rotten.push({0 , {i , j}});
                }
                if(grid[i][j] == 1){
                    one++;
                }
            }
        }
        int ans = 0;
        while(!rotten.empty()){
            auto val = rotten.front();
            rotten.pop();
            int currState = val.first;
            int firstidx = val.second.first;
            int secondidx = val.second.second;
            for(int i = 0 ; i < 4 ; i++){
                int x1 = dir[i][0];
                int y1 = dir[i][1];
                if(firstidx + x1 >= 0 && firstidx + x1 < n && secondidx + y1 >= 0 && secondidx + y1 < m && grid[firstidx + x1][secondidx + y1] == 1){
                        grid[firstidx + x1][secondidx + y1] = 2;
                        rotten.push({currState + 1 , {firstidx + x1 , secondidx + y1}});
                        ans = max(ans , currState + 1);
                        one--;
                }
            }       
        }
        return (one ? -1 : ans);
    }
};