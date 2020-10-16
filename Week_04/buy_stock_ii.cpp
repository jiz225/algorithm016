class Solution {
public:
    /**
    // Greedy: only hold stock when profit > 0
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 0; i < prices.size()-1; i++) {
            if (prices[i+1] > prices[i]) {
                profit += (prices[i+1] - prices[i]);
            }
        }
        return profit;
    }
    **/

    // DP: 2 choices
    // hold cash at i: have stock at i-1 and sell it at i/ have cash at i-1 and donot buy stock at i
    // hold stock at i: no stock at i-1 and buy in stock i/ have stock at i-1 and donot sell it at i
    // profit[i][hold cash at i] = max(profit[i-1][hold cash at i-1],profit[i-1][hold stock at i-1]+price[i])
    // profit[i][hold stock at i] = max(profit[i-1][hold cash at i-1]-price[i],profit[i-1][hold stock at i-1])
    int maxProfit(vector<int>& prices) {
        vector<int> cash;
        vector<int> stock;
        cash.resize(prices.size(),0);
        stock.resize(prices.size(),0);
        for (int i = 0; i < prices.size(); i++) {
            if (i == 0) {
                cash[i] = 0;
                stock[i] = -1*prices[i];
            }
            else {
                cash[i] = max(cash[i-1],stock[i-1]+prices[i]);
                stock[i] = max(cash[i-1]-prices[i],stock[i-1]);
            }
        }
        return cash[prices.size()-1];
    }
};
