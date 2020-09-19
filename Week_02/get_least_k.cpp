class Solution {
public:
    void printQueue(priority_queue<int> q) {
	    while (!q.empty()){
		    cout<<" "<<q.top();
		    q.pop();
	    }
	    cout<<endl;
    }
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        // Priority Queue
        std::priority_queue<int> nums;
        vector<int> leastk;
        if (k < 1) {
            return leastk;
        }
        for (int i = 0; i < k; i++) {
            nums.push(arr[i]);
        }
        for (int i = k; i < arr.size(); i++) {
            if (nums.top() > arr[i]) {
                nums.pop();
                nums.push(arr[i]);
            }
        }
        //printQueue(nums);
        for (int i = 0; i < k; i++) {
            leastk.push_back(nums.top());
            nums.pop();
        }
        return leastk;
    }
};
