class Solution {
public:
    void topo(int i , unordered_map<int,vector<int>>&adj , vector<bool>&visited , stack<int>&st){
        visited[i] = true;
        auto edges = adj[i];
        for(auto &val : edges){
            if(visited[val] == false){
                topo(val , adj , visited , st);
            }
        }
        st.push(i);
        return;
    }
    bool checkCycle(int i , unordered_map<int,vector<int>>&adj , vector<bool>&vis , vector<bool>&dfsvis){
        vis[i] = true;
        dfsvis[i] = true;
        auto edges = adj[i];
        for(auto &val : edges){
            if(vis[val] == false){
                if(checkCycle(val , adj , vis , dfsvis)){
                    return true;
                }
            }else if(dfsvis[val] == true){
                return true;
            }
        }
        dfsvis[i] = false;
        return false;
        
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        unordered_map<int,vector<int>> adj;
        vector<bool> vis(numCourses , false) , dfsvis(numCourses , false);
        for(int i = 0 ; i < prerequisites.size() ; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i = 0 ; i < numCourses ; i++){
            if(vis[i] == false){
                if(checkCycle(i , adj , vis , dfsvis)){
                    return {};
                }
            }
        }
        vector<bool> visited(numCourses , false);
        vector<int> courses;
        stack<int> st;
        for(int i = 0 ; i < numCourses ; i++){
            if(visited[i] == false){
                topo(i , adj , visited , st);
            }
        }
        while(!st.empty()){
            courses.push_back(st.top());
            st.pop();
        }
        return courses;
    }
};