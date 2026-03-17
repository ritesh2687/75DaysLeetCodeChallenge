class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        freq = {}

        for num in nums:
            freq[num] = freq.get(num, 0) + 1

        sorted_items = sorted(freq.items(), key=lambda x: x[1], reverse=True)

        result = [item[0] for item in sorted_items[:k]]

        return result