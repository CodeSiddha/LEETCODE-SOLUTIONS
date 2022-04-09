class Solution {
public:
    // int hash[1e5+1];
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> que;
        // vector<pair<int, int>> arr;
        unordered_map<int,int> mpp;
        for(int i = 0 ; i < n ; i++){
            mpp[nums[i]]++;
        }
        for(auto &x : mpp){
            if(que.empty()){
                que.push({x.second , x.first});                
            }else if(que.size() < k){
                que.push({x.second , x.first});
            }else{
                que.push({x.second , x.first});
                while(que.size() > k){
                    que.pop();
                }
            }
        }
        // for(int i = 0 ; i < arr.size() ; i++){
        //     if(que.empty()){
        //         que.push(arr[i]);                
        //     }else if(que.size() < k){
        //         que.push(arr[i]);
        //     }else{
        //         que.push(arr[i]);
        //         while(que.size() > k){
        //             que.pop();
        //         }
        //     }
        // }
        vector<int> ans;
        while(!que.empty()){
            pair<int,int> top = que.top();
            ans.push_back(top.second);
            que.pop();
        }
        return ans;
    }
};