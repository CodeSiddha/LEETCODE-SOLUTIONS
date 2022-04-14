class Solution {
public:
    
    bool solve(int scr , int des , map<int , vector<int>>&mpp , vector<bool>&visited){
        if(scr == des){
            return true;
        }
        visited[scr] = true;
        for(auto ed : mpp[scr]){
            if(visited[ed] == false){
                bool ans = solve(ed , des , mpp , visited);
                if(ans)
                    return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int m = edges.size();
        vector<bool> visited(n , false);
        map<int , vector<int>> mpp;
        for(int i = 0 ; i < m ; i++){
            mpp[edges[i][0]].push_back(edges[i][1]);
            mpp[edges[i][1]].push_back(edges[i][0]);
        }
        // for(auto &x : mpp){
        //     cout << x.first << ": ";
        //     vector<int> temp = x.second;
        //     for(int i = 0 ; i < temp.size() ; i++){
        //         cout << temp[i] << " ";
        //     }
        //     cout << endl;
        // }
         return solve(source , destination , mpp , visited);    
    }
};