class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

        n=len(nums)
        product_array=[1]*n

        prefix=1
        for i in range(n):
            product_array[i]=prefix
            prefix *= nums[i]

        suffix=1

        for i in range(n-1,-1,-1):
            product_array[i]*= suffix
            suffix*=nums[i]

        return product_array
        