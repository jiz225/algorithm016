class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num;
	    while (left <= right) {
		    int root = left + (right-left)/2;
		    if (num/root == root && num%root == 0) {
                return true;
            }
		    else if ((float) num/root > root) {
                left = root + 1;
            }
		    else right = root - 1;
	    }
	
	    return false;
    }
};
