class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        
        a=0
        b= len(s)-1
        
        while(a<b) :
            left=s[a]
            right=s[b]

            if not s[a].isalnum():
                a=a+1
                continue
            
            if not s[b].isalnum():
                b -=1
                continue

            if left.lower() != right.lower():
                return False
            
            a=a+1
            b=b-1
        
        return True