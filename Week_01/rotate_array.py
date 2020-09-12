class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if (n==0) or (k%n == 0):
            return nums
        k %= n
        while k != 0:
            nums.insert(0,nums.pop())
            k -= 1
        return nums
        '''
        i,j = 0,k
        check = 1
        stack = [nums[i]]
        while check < n:
            stack.append(nums[j])
            nums[j] = stack.pop(0)
            j = int((j+k)%n)
            check += 1
            if i == j:
                nums[j] = stack.pop(0)
                check += 1
                i += 1
                j = i+k
                stack = [nums[i]]
        return nums
        '''
