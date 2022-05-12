class Solution {
    private:
    vector<vector<int>> ans;
public:
   void solve(int i , int target , vector<int>&arr , vector<int>&temp){
       int n = arr.size();
       if(target < 0){
           return;
       }
       if(target == 0){
           ans.push_back(temp);
           return;
       }
       for(int j = i ; j < n ; j++){
           temp.push_back(arr[j]);
           solve(j + 1 , target - arr[j] , arr , temp);
           temp.pop_back();
           while(j + 1 < n and arr[j] == arr[j+1]) j++;
       }
   }
    vector<vector<int>> combinationSum2(vector<int>& arr , int target) {
        sort(arr.begin() , arr.end());
        // vector<vector<int>> ans;
        vector<int> temp;
        solve(0 , target , arr , temp);
        return ans;
    }
};