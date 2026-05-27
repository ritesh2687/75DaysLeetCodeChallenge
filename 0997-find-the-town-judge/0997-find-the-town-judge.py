class Solution(object):
    def findJudge(self, n, trust):
        """
        :type n: int
        :type trust: List[List[int]]
        :rtype: int
        """
        score = [0] * (n + 1)

        for a, b in trust:
            score[a] -= 1
            score[b] += 1

        for i in range(1, n + 1):
            if score[i] == n - 1:
                return i

        return -1
                