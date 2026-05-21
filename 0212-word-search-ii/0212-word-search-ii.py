class TrieNode:
    def __init__(self):
        self.children = {}
        self.word = None


class Solution(object):
    def findWords(self, board, words):
        root = TrieNode()

        for word in words:
            node = root
            for ch in word:
                if ch not in node.children:
                    node.children[ch] = TrieNode()
                node = node.children[ch]
            node.word = word

        rows, cols = len(board), len(board[0])
        result = []

        def dfs(r, c, parent):
            char = board[r][c]

            if char not in parent.children:
                return

            node = parent.children[char]

            if node.word:
                result.append(node.word)
                node.word = None

            board[r][c] = "#"

            for dr, dc in [(1,0), (-1,0), (0,1), (0,-1)]:
                nr, nc = r + dr, c + dc

                if (
                    0 <= nr < rows and
                    0 <= nc < cols and
                    board[nr][nc] != "#"
                ):
                    dfs(nr, nc, node)

            board[r][c] = char

            if not node.children and node.word is None:
                del parent.children[char]

        for r in range(rows):
            for c in range(cols):
                dfs(r, c, root)

        return result