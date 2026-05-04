class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        low, m, high = 0, 0, len(nums) - 1

        while m <= high:
            if nums[m] == 0:
                nums[low], nums[m] = nums[m], nums[low]
                low += 1
                m += 1

            elif nums[m] == 1:
                m += 1

            else:  
                nums[m], nums[high] = nums[high], nums[m]
                high -= 1