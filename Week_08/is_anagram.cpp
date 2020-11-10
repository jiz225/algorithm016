class Solution {
public:
    // string s != string t ???? why hello is anagram of hello
    // sort(s) == sort(t)
    int partition(string& arr, int low, int high) {
        int pivot = arr[high] - '0';
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if ((arr[j] - '0') < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        int pivotIdx = i + 1;
        swap(arr[pivotIdx], arr[high]);
        return pivotIdx;
    }
    void quickSort(string& arr, int left, int right) {
        if (left < right) {
            int pivotIdx = partition(arr, left, right);
            quickSort(arr, left, pivotIdx - 1);
            quickSort(arr, pivotIdx + 1, right);
        }
    }
    bool isAnagram(string s, string t) {
        quickSort(s, 0, s.size()-1);
        quickSort(t, 0, t.size()-1);
        return (s == t);
    }
};
