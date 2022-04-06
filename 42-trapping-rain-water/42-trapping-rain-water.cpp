class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        vector<int> leftmax(n) , rightmax(n);
        for(int i = 1 ; i < n ; i++){
            leftmax[i] = max(height[i - 1] , leftmax[i - 1]);
        }
        for(int i = n - 2 ; i >= 0 ; i--){
            rightmax[i] = max(height[i + 1] , rightmax[i + 1]);
        }
        for(int i = 0 ; i < n ; i++){
            int add = min(leftmax[i], rightmax[i]) - height[i];
            if(add > 0){
                ans += add;
            }
        }
        return ans;
    }
};