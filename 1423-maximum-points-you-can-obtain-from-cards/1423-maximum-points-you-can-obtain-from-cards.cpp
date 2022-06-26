class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        for(int i = 0 ; i < k ; i++){
            sum += cardPoints[i];
        }
        int maxSum = sum;
        int l = k - 1;
        int r = n - 1;
        while(l >= 0 && k){
            sum-=cardPoints[l];
            sum+=cardPoints[r];
            l--;
            r--;
            maxSum = max(maxSum , sum);
            k--;
        }
        return maxSum;
    }
};