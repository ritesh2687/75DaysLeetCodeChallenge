class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        stack = []
        max_area = 0
        n = len(heights)

        for i in range(n + 1):
            curr_height = 0 if i == n else heights[i]

            while stack and curr_height < heights[stack[-1]]:
                h = heights[stack.pop()]

                right = i
                left = stack[-1] if stack else -1

                width = right - left - 1
                max_area = max(max_area, h * width)

            stack.append(i)

        return max_area        