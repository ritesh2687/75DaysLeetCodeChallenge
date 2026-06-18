class Solution {
    vector<vector<bool>> cols;
    vector<vector<bool>> rows;
    vector<vector<bool>> boxes;
public:
    void solveSudoku(vector<vector<char>>& board) {
        cols.resize(9,vector<bool>(10,false));
        rows.resize(9,vector<bool>(10,false));
        boxes.resize(9,vector<bool>(10,false));
        for (int r = 0;r<9;r++) {
            for (int c = 0;c<9;c++) {
                if (board[r][c] != '.') {
                    int d = board[r][c] - '0';
                    cols[c][d] = true;
                    rows[r][d] = true;
                    int b = (r/3) *3  + c/3;
                    boxes[b][d] = true;
                }
            }
        }
        dfs(0,0,board);
    }
    bool dfs(int r,int c,vector<vector<char>>& board) {
        if (r == 9) return true;
        if (c == 9) return dfs(r+1,0,board);
        if (board[r][c] != '.') return dfs(r,c+1,board);
        for (int d = 1;d<=9;d++) {
            char ch = d +'0';
            int b = (r/3) *3  + c/3;
            if (cols[c][d] || rows[r][d] || boxes[b][d]) continue;
            cols[c][d] = true;
            rows[r][d] = true;
            boxes[b][d] = true;
            board[r][c] = ch;
            bool check = dfs(r,c+1,board);
            if (check) return true;
            cols[c][d] = false;
            rows[r][d] = false;
            boxes[b][d] = false;
            board[r][c] = '.';   
        }
        return false;
    }
};