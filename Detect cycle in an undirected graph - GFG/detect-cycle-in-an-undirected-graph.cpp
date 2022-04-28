// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    
    bool isCycle(int V, vector<int> adj[]) {
        // Using BFS;
        vector<bool> visited(V + 1 , false);
        queue<int> que;
        for(int i = 0 ; i < V ; i++){
            if(visited[i] == false){
            que.push(i);
            while(!que.empty()){
            if(visited[que.front()]){
                return true;
            }
            int curr = que.front();
            visited[curr] = true;
            auto x = adj[curr];
            for(auto num : x){
                if(visited[num] == false){
                    // visited[num] = true;
                    que.push(num);
                }
            }
                    que.pop();
                }        
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends