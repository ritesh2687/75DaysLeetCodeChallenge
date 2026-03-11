class Solution(object):
    def sortedSquares(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        i=0
        j=len(nums)-1
        k=len(nums)-1
        res = [0]*len(nums)

        while i<=j:
            if abs(nums[i])>abs(nums[j]):
                res[k]=nums[i]*nums[i]
                i +=1
            else :
                res[k]=nums[j]*nums[j] 
                j -=1
            k -=1

        return res
