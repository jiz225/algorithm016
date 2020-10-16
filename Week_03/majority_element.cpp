class Solution {
public:
    /**
    // divide and conquer: O(nlogn)
    int countFreq(vector<int>& nums, int num, int start, int end) {
        int freq = 0;
        for (int i = start; i <= end; i++) {
            if (nums[i] == num) {
                freq ++;
            }
        }
        return freq;
    }
    int findMajority(vector<int>& nums, int start, int end) {
        if (start == end) {
            return nums[start];
        }
        int l_maj = findMajority(nums,start,(start+end)/2);
        int r_maj = findMajority(nums,(start+end)/2+1,end);
        if (countFreq(nums,l_maj,start,end) > (end - start + 1)/2) {
            return l_maj;
        }
        else {
            return r_maj;
        }
    }
    int majorityElement(vector<int>& nums) {
        return findMajority(nums,0,nums.size()-1);
    }**/

    // Boyer-Moore voting: 
    // if f(nums[i]) > l(nums)/2, f(nums[i]) - SUM(f(num[j]),j=0...l(nums)-1 and j!=i)
    // if f(nums[i]) - SUM(f(num[j])) == 0, i += 1
    int majorityElement(vector<int>& nums) {
        int i = 0;
        int count = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (count == 0) {
                i = j;
            }
            if (nums[i] == nums[j]) {
                count ++;
            }
            else {
                count --;
            }
        }
        return nums[i];
    }
};
