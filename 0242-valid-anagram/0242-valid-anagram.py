class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        # if(sorted(s)==sorted(t)):
        #     return True
        # return False

        # if len(s) != len(t):
        #     return False

        # check={}

        # for c in s:
        #     check[c]=check.get(c,0)+1
        
        # for c in t:
        #     if c not in check or check[c]==0:
        #         return False
        #     check[c] -=1
        
        # return True

       
        if len(s) != len(t):
            return False
    
        count = [0]*26
        for a,b in zip(s,t):
            count[ord(a)-97]+=1
            count[ord(b)-97]-=1
        
        return count == [0]*26