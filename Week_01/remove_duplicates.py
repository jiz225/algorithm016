class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l,r = 0,0
        while r < len(nums)-1:
            r += 1
            nums[l+1] = nums[r]
            if nums[l] != nums[l+1]:
                l += 1
        return l+1
