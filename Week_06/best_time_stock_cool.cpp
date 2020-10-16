class Solution {
public:
    // P[i][cool] = max(P[i-1][cash], P[i-1][cool])
    // P[i][cash] = max(P[i-1][stock] + p[i], P[i-1][cash])
    // P[i][stock] = max(P[i-1][cool] - p[i], P[i-1][stock])
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int cool = 0, cash = 0, stock = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            int prev = stock;
            stock = max(cool - prices[i],stock);
            cool = max(cool, cash);
            cash = max(prev + prices[i], cash);
        }
        return max(cool,cash);
    }
};
