class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0
    
        min_val = prices[0]
        max_diff = 0
    
        for i in range(1, len(prices)):
            if prices[i] > min_val:
                max_diff = max(max_diff, prices[i] - min_val)
            else:
                min_val = prices[i]
    
        return max_diff