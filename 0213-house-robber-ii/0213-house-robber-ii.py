class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 1:
            return nums[0]

        def robLine(houses):
            prev1 = prev2 = 0
            for num in houses:
                prev1, prev2 = max(prev2 + num, prev1), prev1
            return prev1

        return max(robLine(nums[:-1]), robLine(nums[1:]))        