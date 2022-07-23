class Solution {
public:
    vector<pair<int,pair<int,int>>> merge(vector<pair<int,pair<int,int>>>&a , vector<pair<int,pair<int,int>>>&b){
        vector<pair<int,pair<int,int>>> ans;
        int i = 0;
        int j = 0;
        int rightIsSmallerThanLeft = 0;
        while(i < a.size() && j < b.size()){
            if(a[i].second.first <= b[j].second.first){
                a[i].second.second += rightIsSmallerThanLeft;
                ans.push_back(a[i]);
                i++;
            }else if(a[i].second.first > b[j].second.first){
                rightIsSmallerThanLeft++;
                ans.push_back(b[j]);
                j++;
            }
        }
        while(i < a.size()){
            a[i].second.second += rightIsSmallerThanLeft;
            ans.push_back(a[i]);
            i++;
        }
        while(j < b.size()){
            ans.push_back(b[j]);
            j++;
        }
        return ans;
    }
    vector<pair<int,pair<int,int>>> mergeSort(vector<int>&nums , int lo , int hi){
        if(lo == hi){
            return {{lo,{nums[lo] , 0}}};

        }
        int mid = (lo + hi) / 2;
        vector<pair<int,pair<int,int>>> la = mergeSort(nums , lo , mid);
        vector<pair<int,pair<int,int>>> ra = mergeSort(nums , mid + 1 , hi);
        return merge(la , ra);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,pair<int,int>>> arr;
        for(int i = 0 ; i  < n ; i++){
            arr.push_back({i , {nums[i] , 0}});
        }
        vector<pair<int,pair<int,int>>> ans = mergeSort(nums , 0 , n - 1);
        vector<int> finalRes(n , 0);
        for(int i = 0 ; i < n ; i++){
            finalRes[ans[i].first] = ans[i].second.second;
        }
        return finalRes;
    }
};