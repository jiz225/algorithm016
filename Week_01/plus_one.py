class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        i = len(digits)-1
        while i >= 0:
            digits[i] = digits[i]+1
            if digits[i] == 10:
                digits[i] = 0
                i -= 1
            else:
                return digits
        digits.insert(0,1)
        return digits
