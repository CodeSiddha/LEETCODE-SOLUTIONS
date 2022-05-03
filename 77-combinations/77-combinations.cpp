class Solution {
public:
    void solve(int i , int &n , int &k , vector<vector<int>>&ans , vector<int> &temp){ 
         if(temp.size() == k){
             ans.push_back(temp);
             return;
        }
        for(int j = i ; j <= n ; j++){
            temp.push_back(j);
            solve(j + 1 , n , k , ans , temp);            
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
            solve( 1 , n , k , ans , temp);            
        
        return ans;
    }
};


// vector<vector<int>> ans;
//         set<vector<int>> s;
//         for(int i = 1 ; i <= n ; i++){
//             vector<int> temp;
//             for(int j = i ; j <= n ; j++){
//                 temp.push_back(j);
//                 s.insert(temp);
//             }
//         }
//         for(auto &x : s){
//             if(x.size() == k){
//                 ans.push_back(x);
//             }
//         }
//         return ans;