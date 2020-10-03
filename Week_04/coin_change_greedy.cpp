class Solution {
public:
    int minC = INT_MAX;
    void coinGreedy(vector<int>& coins, int amount, int idx, int numC) {
        if (idx >= coins.size()) {
            return;
        }
        int num_i = amount/coins[idx];
        while (num_i >= 0) {
            int reminder = amount - coins[idx]*num_i;
            int total = numC+num_i;
            if (reminder == 0) {
                minC = min(minC,total);
                return;
            }
            if (total >= minC) {
                return;
            }
            coinGreedy(coins, reminder, idx+1, total);
            num_i --;
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.rbegin(),coins.rend());
        coinGreedy(coins, amount, 0, 0);
        if (minC == INT_MAX) {
            return -1;
        }
        return minC;
    }
};
