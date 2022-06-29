
class Solution {
public:
    static bool cmp(vector<int>&a , vector<int>&b){
        if(a[0] == b[0]){
            return a[1] < b[1];
        }else if(a[0] > b[0]) return true;
        return false;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        vector<vector<int>> ans;
        sort(people.begin() , people.end() , cmp);
        for(int i = 0 ; i < n ; i++){
            ans.insert(people[i][1] + ans.begin() , people[i]);
        }       
        return ans;
    }
};