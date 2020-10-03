class Solution {
public:
    // F(amount) = F(amount - coin) + 1 bottom to top
    vector<int> nums;
    int coinChange(vector<int>& coins, int amount) {
        nums.resize(amount+1,0);
        for (int i = 1; i < nums.size(); i++) {
            int minC = INT_MAX;
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i && nums[i - coins[j]] >= 0) {
                    int num = nums[i - coins[j]] + 1;
                    if (num < minC) {
                        minC = num;
                    }
                }
            }
            if (minC == INT_MAX) {
                nums[i] = -1;
            }
            else {
                nums[i] = minC;
            }
            //cout << " " << i << "-" << nums[i];
        }
        return nums[amount];
    }
    /**
    // F(amount) = F(amount - coin) + 1 top to bottom
    vector<int> nums;
    int findCoinComb(vector<int>& coins, int amount){
        if (amount == 0) {
            return 0;
        }
        if (amount < 0) {
            return -1;
        }
        if (nums[amount-1] != 0) {
            return nums[amount-1];
        }
        int minC = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int num = findCoinComb(coins, amount-coins[i]);
            if (num != -1 && num + 1 < minC) {
                minC = num + 1;
            }
        }
        if (minC == INT_MAX) {
            nums[amount-1] = -1;
        }
        else {
            nums[amount-1] = minC;
        }
        return nums[amount-1];
    }
    int coinChange(vector<int>& coins, int amount) {
        nums.resize(amount,0);
        return findCoinComb(coins, amount);
    }
    **/
};
