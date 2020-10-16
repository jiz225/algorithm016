class Solution {
public:
    // P[i][max] = max(P[i-1][max]*N[i], P[i-1][min]*N[i], N[i])
    // P[i][min] = min(P[i-1][max]*N[i], P[i-1][min]*N[i], N[i])
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int maxProd = nums[0];
        int minProd = nums[0];
        int maxP = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int maxPrev = maxProd, minPrev = minProd;
            maxProd = max(max(maxPrev*nums[i], minPrev*nums[i]), nums[i]);
            minProd = min(min(maxPrev*nums[i], minPrev*nums[i]), nums[i]);
            maxP = max(maxP,maxProd);
        }
        return maxP;
    }
};
