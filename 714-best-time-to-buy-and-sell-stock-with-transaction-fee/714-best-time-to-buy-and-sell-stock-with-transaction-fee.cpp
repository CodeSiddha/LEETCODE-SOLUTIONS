class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = -prices[0];
        int sell = 0;
        for(int i = 1 ; i < prices.size() ; i++){
            int newbuy = max(buy , sell - prices[i]);
            int newsell = max(sell , (prices[i] + buy) - fee);
            buy = newbuy;
            sell = newsell;
        }
        return sell;
    }
};