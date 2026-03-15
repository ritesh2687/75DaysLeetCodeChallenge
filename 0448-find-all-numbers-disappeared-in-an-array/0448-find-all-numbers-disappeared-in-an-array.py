class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        for num in nums:
            nums[abs(num)-1] *= -1 if nums[abs(num)-1] > 0 else 1
        return [i+1 for i, x in enumerate(nums) if x > 0]
        