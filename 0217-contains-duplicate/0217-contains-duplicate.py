class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        # """
        # freq={}
        # for num in nums:
        #     if num in freq:
        #         freq[num]+=1
        #     else:
        #         freq[num]=1
        # for key in freq:
        #     if freq[key]>1:
        #         return True
            
        # return False

        se =set()
        for num in nums:
            if num in se:
                return True
            se.add(num)
        return False

        