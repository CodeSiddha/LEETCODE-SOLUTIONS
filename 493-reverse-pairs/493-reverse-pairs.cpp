class Solution {
public:
    vector<int> Merge(vector<int>&a , vector<int>&b , int &pair){
        vector<int> ans;
        int i = 0;
        int j = 0;
        for (int i = 0; i < a.size(); i++) {
            while (j < b.size() && a[i] > 2LL * b[j]){
                j++;
            }       
            pair += (j);
        }
        i = 0;
        j = 0;
        while(i < a.size() && j < b.size()){
            if(a[i] <= b[j]){
                ans.push_back(a[i]);
                i++;
            }else{
                ans.push_back(b[j]);
                j++;
            }
        }
        while(i < a.size()){
            ans.push_back(a[i]);
            i++;
        }
        while(j < b.size()){
            ans.push_back(b[j]);
            j++;
        }
        return ans;
    }
    vector<int> MergeSort(vector<int>&nums , int lo , int hi , int &pair){
        if(lo == hi){
            return {nums[lo]};
        }
        int mid = (lo + hi) / 2;
        
        vector<int> lh = MergeSort(nums , lo , mid , pair);
        vector<int> rh = MergeSort(nums , mid + 1 , hi , pair);
        
        vector<int> ans = Merge(lh , rh , pair);
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int pair = 0;
        MergeSort(nums , 0 , n - 1 , pair);
        return pair;
    }
};