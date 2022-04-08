class KthLargest {
    private:
    priority_queue<int ,vector<int>, greater<int>> pq , helper;
    int kth;
public:
    KthLargest(int k, vector<int>& nums) {
        int n = nums.size();
        kth = k;
        for(int i = 0 ; i < n ; i++){
            pq.push(nums[i]);
        }
        while(pq.size() > kth){
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size() > kth){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */