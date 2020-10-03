class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int left = 0, right = matrix[0].size()*matrix.size() - 1;
        while (left <= right) {
            int mid = (left + right)/2;
            if (matrix[mid/matrix[0].size()][mid%matrix[0].size()] == target) {
                return true;
            }
            else if (matrix[mid/matrix[0].size()][mid%matrix[0].size()] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return false;
    }
};
