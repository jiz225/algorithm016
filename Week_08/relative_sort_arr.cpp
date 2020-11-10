class Solution {
public:
    void merge(vector<int>& arr, int left, int mid, int right) {
        vector<int> tmp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        while (i <= mid && j <= right) {
            tmp[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
        }
        while(i <= mid) {
            tmp[k++] = arr[i++];
        }
        while(j <= right) {
            tmp[k++] = arr[j++];
        }
        for (i = left, k = 0; i <= right;) {
            arr[i++] = tmp[k++];
        }
    }
    void mergeSort(vector<int>& arr, int left, int right) {
        if (left >= right) return;
        int mid = (left + right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> sorted;
        unordered_map<int, int> freq;
        for (int num: arr1) {
            if (freq.find(num) != freq.end()) {
                freq[num] = freq[num]+1;
            }
            else {
                freq[num] = 1;
            }
        }
        for (int i = 0; i < arr2.size(); i++) {
            sorted.insert(sorted.end(), freq[arr2[i]], arr2[i]);
            freq.erase(arr2[i]);
        }
        int left = sorted.size();
        for (pair<int, int> p: freq) {
            sorted.insert(sorted.end(), p.second, p.first);
        }
        mergeSort(sorted, left, sorted.size()-1);
        return sorted;
    }
};
