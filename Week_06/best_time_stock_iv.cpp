class Solution {
public:
    // j in [1....k] where for each j, bj is buy in and sj is sell
    // there are 2k states for each i
    // P[i][0] = P[i-1][0] = 0
    // P[i][b_j] = max(P[i-1][s_j-1] - p[i], P[i-1][b_j])
    // P[i][s_j] = max(P[i-1][b_j] + p[i], P[i-1][s_j])
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty() || k == 0) {
            return 0;
        }
        if (k >= prices.size()/2) {
            int maxP = 0;
            for (int i = 1; i < prices.size(); i++) {
                if (prices[i] > prices[i-1]) {
                    maxP += (prices[i]-prices[i-1]);
                }
            }
            return maxP;
        }
        int maxP = 0;
        vector<int> sell(1,0);
        vector<int> buy(1,-prices[0]);
        for (int i = 1; i < prices.size(); i++) {
            for (int j = min(i,k-1); j >= 1; j--) {
                if (j < buy.size()) {
                    sell[j] = max(buy[j] + prices[i], sell[j]);
                    buy[j] = max(sell[j-1] - prices[i], buy[j]);
                }
                else {
                    sell.push_back(0);
                    buy.push_back(sell[j-1] - prices[i]);
                }
            }
            sell[0] = max(buy[0] + prices[i], sell[0]);
            buy[0] = max(-prices[i], buy[0]);
        }
        for (int i = 0; i < sell.size(); i ++) {
            maxP = max(maxP, sell[i]);
        }
        return maxP;
    }
};
