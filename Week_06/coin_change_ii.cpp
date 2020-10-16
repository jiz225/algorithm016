class Solution {
public:
    // coins = {1...j...l(coins)}
    // F[j][i] = F[j-1][i] + F[j][i-coins[j]]
    int change(int amount, vector<int>& coins) {
        vector<int> changes(amount+1, 0);
        changes[0] = 1;
        for (int j = 0; j < coins.size(); j++) {
            for (int i = coins[j]; i <= amount; i++) {
                changes[i] += changes[i-coins[j]];
            }
        }
        return changes[amount];
    }
};
