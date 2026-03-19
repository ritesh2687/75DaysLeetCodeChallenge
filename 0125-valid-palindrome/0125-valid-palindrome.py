class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        
        a=0
        j= len(s)-1
        
        while(a<j) :
            left=s[a]
            right=s[j]

            if not s[a].isalnum():
                a=a+1
                continue
            
            if not s[j].isalnum():
                j -=1
                continue

            if left.lower() != right.lower():
                return False
            
            a=a+1
            j=j-1
        
        return True