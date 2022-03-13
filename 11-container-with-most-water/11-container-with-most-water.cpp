class Solution {
public:
    int maxArea(vector<int>& height) {
        int n  = height.size();
        int s = 0;
        int e = n - 1;
        int maxWater = 0;
        while(s < e){
            maxWater = max(maxWater , (min(height[s] , height[e]) * (e - s)));
            if(height[s] < height[e]){
                s++;
            }else if(height[s] > height[e]){
                e--;
            }else{
                if(s + 1 < e - 1){
                    if(height[s + 1] < height[e - 1]){
                        s++;
                    }else{
                        e--;
                    }
                }else{
                    break;
                }
            }
        }
        return maxWater;
    }
};