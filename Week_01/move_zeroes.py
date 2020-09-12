class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        l,r = 0,0
        while r < len(nums):
            if nums[r] != 0:
                nums[l] = nums[r]
                if r != l:
                    nums[r] = 0
                l += 1
            r += 1
        return nums
