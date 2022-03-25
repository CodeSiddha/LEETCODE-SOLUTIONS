class Solution {
public:
    static bool cmp(const pair<int , int> &a , const pair<int,int> &b){
        return a.first < b.first;
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<pair<int , int>> diff;
        for(int i = 0 ; i < n ; i++){
            diff.push_back({costs[i][0] - costs[i][1] , i});
        }
        sort(diff.begin() , diff.end());
        int till = n/2;
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(till){
                ans += costs[diff[i].second][0];
            }else{
                ans += costs[diff[i].second][1];
            }
            if(till){
                till--;
            }
        }
        return ans;
    }
};