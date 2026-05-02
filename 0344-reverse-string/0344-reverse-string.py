class Solution(object):
    def reverseString(self, s):
        """
        :type s: List[str]
        :rtype: None Do not return anything, modify s in-place instead.
        """
        strt=0
        j=len(s)-1
        while strt<j:
            temp=s[strt]
            s[strt]=s[j]
            s[j]=temp

            strt=strt+1
            j -=1
        