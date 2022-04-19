class Solution {
public:
    void DFS(vector<vector<int>>&isConnected , int i , vector<bool>& visited){
        if(i < 0 || i >= isConnected.size() ){
            return ;
        }
        if(visited[i] == true){
            return;
        }
        
        for(int j = 0 ; j < isConnected[0].size() ; j++){
            if(isConnected[i][j] == 1){
                visited[i] = true;
                DFS(isConnected , j , visited);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<bool> visited(n , false);
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
               if(isConnected[i][j] == 1 && visited[i] == false){
                   DFS(isConnected , i , visited);
                   ans++;
               }
            }
        }
        return ans;
    }
};