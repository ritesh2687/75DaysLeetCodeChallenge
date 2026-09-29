class Solution {
    bool dfs(vector<vector<char>>& grid, int i, int j, int bal, vector<vector<vector<bool>>>& vis) {
        bal += grid[i][j] == '(' ? 1 : -1;
        int m = grid.size(), n = grid[0].size();
        
        if (bal < 0 || bal > (m + n) / 2 || vis[i][j][bal]) return false;
        if (i == m - 1 && j == n - 1) return bal == 0;
        
        vis[i][j][bal] = true;
        
        if (i + 1 < m && dfs(grid, i + 1, j, bal, vis)) return true;
        if (j + 1 < n && dfs(grid, i, j + 1, bal, vis)) return true;
        
        return false;
    }
    
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if ((m + n - 1) % 2 != 0 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }
        
        vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(m + n, false)));
        return dfs(grid, 0, 0, 0, vis);
    }
};