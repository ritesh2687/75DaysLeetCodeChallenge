class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        dictionary = {}

        for string in strs:
            count_arr = [0] * 26

            for letter in string:
                count_arr[ord(letter) - ord('a')] += 1

            key = tuple(count_arr)

            if key not in dictionary:
                dictionary[key] = []

            dictionary[key].append(string)

        return dictionary.values()