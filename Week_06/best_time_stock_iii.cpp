class Solution {
public:
    // P[i][0] = P[i-1][0]
    // P[i][buy 1] = max(P[i-1][0] - p[i], P[i-1][b1])
    // P[i][sell 1] = max(P[i-1][b1] + p[i], P[i-1][s1])
    // P[i][buy 2] = max(P[i-1][s1] - p[i], P[i-1][b2])
    // P[i][sell 2] = max(P[i-1][b2] + p[i], P[i-1][s2])
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        vector<int> profit(4,0);
        profit[0] = -prices[0];
        profit[2] = INT_MIN;
        for (int i = 1; i < prices.size(); i++) {
            profit[3] = max(profit[2] + prices[i], profit[3]);
            profit[2] = max(profit[1] - prices[i], profit[2]);
            profit[1] = max(profit[0] + prices[i], profit[1]);
            profit[0] = max(-prices[i], profit[0]);
        }
        return max(profit[1],profit[3]);
    }
};
