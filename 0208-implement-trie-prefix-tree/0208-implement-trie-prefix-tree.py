class Trie(object):

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        """ 
        :type word: str
        :rtype: None
        """
        node = self.root
        for ch in word:
            if ch not in node.children:
                node.children[ch] = TrieNode()
            node = node.children[ch]
        node.is_end = True

    def search(self, word):
        """ 
        :type word: str 
        :rtype: bool 
        """
        node = self._traverse(word)
        return node is not None and node.is_end

    def startsWith(self, prefix):
        """ 
        :type prefix: str 
        :rtype: bool 
        """
        return self._traverse(prefix) is not None

    def _traverse(self, string):
        node = self.root
        for ch in string:
            if ch not in node.children:
                return None
            node = node.children[ch]
        return node


class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end = False