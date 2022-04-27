class Solution {
public:
    void DFS(map<int,vector<int>>&mpp, string &s , vector<bool>&visited , int i ,vector<pair<char , int>>&charidx){
        charidx.push_back({s[i] , i});
            auto e = mpp[i];
            for(auto num : e){
                    if(visited[num] == false){
                    visited[num] = true;
                    DFS(mpp , s , visited , num , charidx);
                }   
            }
        return;
    }
    void solve(vector<pair<char , int>>& arr , string &s){
        vector<int> sortThis;
        for(int i = 0 ; i < arr.size() ; i++){
            sortThis.push_back(arr[i].second);
        }
        sort(sortThis.begin() , sortThis.end());
        sort(arr.begin() , arr.end());
        for(int i = 0 ; i < sortThis.size() ; i++){
            s[sortThis[i]] = arr[i].first;
        }
        return;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = pairs.size();
        map<int, vector<int>> mpp;
        for(int i = 0 ; i < n ; i++){
            mpp[pairs[i][0]].push_back(pairs[i][1]);            
            mpp[pairs[i][1]].push_back(pairs[i][0]);
        }
        int m = s.size();
        vector<bool> visited(m , false);
        vector<vector<pair<char , int>>> connectedComponents;
        for(int i = 0 ; i < m ; i++){
            vector<pair<char , int>> charidx;
            if(visited[i] == false){
                visited[i] = true;
                DFS(mpp , s , visited , i , charidx);
            }
            if(charidx.size() != 0)
            connectedComponents.push_back(charidx);
        }
        n = connectedComponents.size();
        for(int i = 0 ; i < n ; i++){
            solve(connectedComponents[i] , s);
        }
        return s;
    }
};