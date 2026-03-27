class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        char_set = set()
        left = 0
        m_length = 0
    
        for right in range(len(s)):
            while s[right] in char_set:
                char_set.remove(s[left])
                left += 1
        
            char_set.add(s[right])
            m_length = max(m_length, right - left + 1)
    
        return m_length    