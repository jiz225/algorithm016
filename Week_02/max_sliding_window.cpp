class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Dequeue: max = head
        std::deque<int> window;
        vector<int> maxn;
        for (int i = 0; i < nums.size(); i++) {
            while (!window.empty() && nums[window.back()] < nums[i]) {
                window.pop_back();
            }
            window.push_back(i);
            if (i >= k-1) {
                //cout << " " << nums[window.front()];
                maxn.push_back(nums[window.front()]);
                if (i - window.front() >= k - 1) {
                    window.pop_front();
                }
            }
        }
        return maxn;
    }
};
