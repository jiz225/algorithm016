class Solution {
public:
    // P[i][stock] = max(P[i-1][cash] - p[i], P[i-1][stock])
    // P[i][cash] = max(P[i-1][stock] + p[i] - fee, P[i-1][cash])
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.empty()) {
            return 0;
        }
        int cash = 0, stock = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            int prev = stock;
            stock = max(cash - prices[i],stock);
            cash = max(prev + prices[i] - fee, cash);
        }
        return cash;
    }
};
