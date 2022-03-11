class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> forward(n) , backward(n);
        //forward
        //if we sell at this point how much max profit we get.
        int minstock = prices[0];
        int currmax = 0;
        for(int i = 1 ; i < n ; i++){    
            if(prices[i] < minstock){
                minstock = prices[i];
            }
            currmax = (prices[i] - minstock);
            if(currmax > forward[i - 1]){
                forward[i] = currmax;
            }else{
                forward[i] = forward[i - 1];
            }
        }
        //backward.
        //if we buy at this day what max profit we'll get in future.
        int maxstock = prices[n - 1];
        currmax = 0;
        for(int i = n - 2 ; i >= 0 ; i--){
            if(prices[i] > maxstock){
                maxstock = prices[i];
            }
            currmax = maxstock - prices[i];
            if(currmax > backward[i + 1]){
                backward[i] = currmax;
            }else{
                backward[i] = backward[i + 1];
            }
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            ans = max(ans, forward[i] + backward[i]);
        }
        return ans;
    }
};