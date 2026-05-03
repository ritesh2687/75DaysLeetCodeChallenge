class Solution(object):
    def sortedSquares(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        strt=0
        j=len(nums)-1
        k=len(nums)-1
        res = [0]*len(nums)

        while strt<=j:
            if abs(nums[strt])>abs(nums[j]):
                res[k]=nums[strt]*nums[strt]
                strt+=1
            else :
                res[k]=nums[j]*nums[j] 
                j -=1
            k -=1

        return res
