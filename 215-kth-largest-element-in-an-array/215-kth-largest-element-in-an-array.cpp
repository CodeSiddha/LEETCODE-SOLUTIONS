class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int , vector<int> , greater<int>> pq;
        for(int i = 0 ; i < n ; i++){
            if(pq.size() < k){
                pq.push(nums[i]);
            }else{
                pq.push(nums[i]);
                while(pq.size() > k)
                pq.pop();
            }
        }
        // while(pq.size() > 1){
        //     pq.pop();
        // }
        return pq.top();
    }
};