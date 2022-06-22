class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n > m){
            swap(nums1 , nums2);
            swap(n , m);
        }
        unordered_map<int,int>mpp;
        for(int i = 0 ; i < m ; i++){
            mpp[nums2[i]]++;
        }
        vector<int> ans;
        for(int i = 0 ; i < n ; i++){
            if(mpp.count(nums1[i]) && mpp[nums1[i]] > 0){
                ans.push_back(nums1[i]);
                mpp[nums1[i]]--;
            }
        }
        return ans;
    }
};