class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        r = [set() for _ in range(9)]
        c = [set() for _ in range(9)]
        box = [set() for _ in range(9)]
        
        for i in range(9):
            for j in range(9):
                val = board[i][j]
                
                if val == '.':
                    continue
                
                box_index = (i // 3) * 3 + (j // 3)
                
                if (val in r[i] or 
                    val in c[j] or 
                    val in box[box_index]):
                    return False
                
                r[i].add(val)
                c[j].add(val)
                box[box_index].add(val)
        
        return True        