class Solution {
    private:
    vector<int> arr;
    int n;
public:
    Solution(vector<int>& w) {
        n = w.size();
        arr.push_back(w[0]);
        for(int i = 1 ; i < n ; i++){
            arr.push_back(w[i] + arr[i - 1]);  
        }
    }
    
    int pickIndex() {
        int ran = rand() % arr[n - 1] + 1;
        int idx = lower_bound(arr.begin() , arr.end() , ran) - arr.begin();
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */