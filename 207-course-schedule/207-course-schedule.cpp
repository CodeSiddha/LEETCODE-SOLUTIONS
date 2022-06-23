class Solution {
public:
    bool checkCycle(unordered_map<int,vector<int>>&adj , int i , vector<bool>&vis , vector<bool>&dfsvis){
        vis[i] = true;
        dfsvis[i] = true;
        auto edges = adj[i];
        for(int val : edges){
            if(vis[val] == false){
                if(checkCycle(adj , val , vis ,dfsvis) == true)
                    return true;
            }else if(dfsvis[val] == true){
                return true;
            }
        }
        dfsvis[i] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses , false) , dfsvis(numCourses , false);
        unordered_map<int , vector<int>> adj;
        for(int i = 0 ; i < prerequisites.size() ; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i = 0 ; i < numCourses ; i++){
            if(vis[i] == false){
                if(checkCycle(adj , i , vis , dfsvis)){
                    return false;
                }
            }
        }
        return true;
    }
};