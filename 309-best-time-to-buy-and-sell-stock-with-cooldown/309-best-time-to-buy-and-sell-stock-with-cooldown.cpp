class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = -prices[0];
        int sell = 0;
        int cooldown = 0;
        for(int i = 1 ; i < prices.size() ; i++){
            int newbuy = max(buy , cooldown - prices[i]);
            int newsell = max(sell , prices[i] + buy);
            int newcooldown = max(cooldown , sell);
            buy = newbuy;
            sell = newsell;
            cooldown = newcooldown;
        }
        return sell;
    }
};