class Solution {
public:
    bool BFS(vector<vector<int>>& graph , int src , vector<bool>&visited , set<int>&s1 , set<int>&s2 , bool fors1){
        queue<int> que;
        que.push(src);
        s1.insert(src);
        fors1 = false;
        while(!que.empty()){
            int level  = que.size();
            for(int i = 0 ; i < level ; i++){
                    int want = que.front();
                    if(visited[want] == true){
                        if(fors1){
                            if(s1.count(want)){
                                return false;
                            }
                        }else{
                            if(s2.count(want)){
                                return false;
                            }
                        }
                        return true;
                    }
                    visited[want] = true;
                    if(fors1){
                        auto edges = graph[want];
                        for(auto num : edges){
                            if(visited[num] == false){
                                s1.insert(num);
                                que.push(num);   
                            }
                        }
                    }else{
                        auto edges = graph[want];
                        for(auto num : edges){
                            if(visited[num] == false){
                                 s2.insert(num);
                                 que.push(num);   
                            }
                        }
                    }
                    que.pop();
                }
                fors1 = !fors1;        
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        set<int> s1 , s2; 
        vector<bool> visited(n , false);
        for(int i = 0 ; i < n ; i++){
            if(visited[i] == false){
                bool ans = true; 
                ans = BFS(graph , i , visited , s1 , s2 , true);
                if(ans == false){
                    return false;
                }    
            }
        }
            

       // for (auto it = s1.begin(); it !=s1.end(); ++it)
       //          cout << " " << *it;
       //  cout << endl;
       //   for (auto it = s2.begin(); it !=s2.end(); ++it)
       //          cout << " " << *it;
       //  cout << endl;
      
        
        return true;
    }
};