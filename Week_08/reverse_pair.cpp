class Solution {
public:
    // mergesort: nums[l:(l+r)/2] and nums[(l+r)/2+1:r] are sorted
    // N(l,r) = N(nums[i] > nums[j]*2) where l<=i<=(l+r)/2 and (l+r)/2<j<=r
    void merge(vector<int>& nums, int left, int mid, int right){
        int n1 = mid - left + 1, n2 = right - mid;
        int L[n1], R[n2];
        for (int i = 0; i < n1; i++){
            L[i] = nums[left + i];
        }
        for (int j = 0; j < n2; j++){
            R[j] = nums[mid + 1 + j];
        }
        int i = 0, j = 0;
        for (int k = left; k <= right; k++) {
            if (j >= n2 || (i < n1 && L[i] <= R[j])) {
                nums[k] = L[i++];
            }  
            else {
                nums[k] = R[j++];
            } 
        }
    }
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return 0;
        }
        
        int mid = (left + right)/2;
        int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);
        int i = left, j = mid + 1;
        while (i <= mid) {
            while (j <= right && nums[i] > (nums[j] * 2LL)) {
                j++;
            }
            count += j - mid - 1;
            i++;
        }
        merge(nums, left, mid, right);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
