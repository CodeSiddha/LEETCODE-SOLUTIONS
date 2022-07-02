class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        int n = horizontalCuts.size();
        int m = verticalCuts.size();
        
        sort(horizontalCuts.begin() , horizontalCuts.end());
        sort(verticalCuts.begin() , verticalCuts.end());

        int maxArea = 0;
        int maxDiffInHorizontal = horizontalCuts[0];
        int maxDiffInVertical = verticalCuts[0];
        for(int i = 1 ; i < n ; i++){
                maxDiffInHorizontal = max(maxDiffInHorizontal , horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        maxDiffInHorizontal = max(maxDiffInHorizontal , h - horizontalCuts[n - 1]);
        for(int i = 1 ; i < m ; i++){
            maxDiffInVertical = max(maxDiffInVertical , verticalCuts[i] - verticalCuts[i - 1]);
        }
        maxDiffInVertical = max(maxDiffInVertical , w - verticalCuts[m - 1]);
        return (1ll* maxDiffInHorizontal * maxDiffInVertical)%1000000007;
    }
};