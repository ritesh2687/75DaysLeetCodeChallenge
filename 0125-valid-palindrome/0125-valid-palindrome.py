class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        
        i=0
        j= len(s)-1
        
        while(i<j) :
            left=s[i]
            right=s[j]

            if not s[i].isalnum():
                i=i+1
                continue
            
            if not s[j].isalnum():
                j -=1
                continue

            if left.lower() != right.lower():
                return False
            
            i=i+1
            j=j-1
        
        return True