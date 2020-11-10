class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        sort(intervals.begin(), intervals.end());
        int j = 0;
        for (int i = 0; i < intervals.size(); i++) {
            if (merged.empty()) {
                merged.push_back(intervals[i]);
            }
            else{
                if (merged[j][1] >= intervals[i][0]) {
                    merged[j][1] = max(merged[j][1], intervals[i][1]);
                }
                else {
                    merged.push_back(intervals[i]);
                    j++;
                }
            }
        }
        return merged;
    }
};
