class Solution {
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    vector<vector<bool>> vis;
    int n, m;
public:
    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size(); m = grid[0].size();
        vis.resize(n,vector<bool>(m,false));
        for (int i = 0;i<n;i++) {
            for (int j = 0;j<m;j++) {
                if (vis[i][j])  continue;
                bool check = dfs(grid,i,j,-1,-1);
                if (check) return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& grid,int x,int y,int px,int py) {
        if (vis[x][y]) return false;
        vis[x][y] = true;
        char curr = grid[x][y];
        for (int k = 0;k<4;k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx <0 || nx == n || ny < 0 || ny == m || grid[nx][ny] != curr) continue;

            if (vis[nx][ny] && (nx != px && ny != py)) return true;
            if (vis[nx][ny]) continue;
            bool check = dfs(grid,nx,ny,x,y);
            if (check) return true;
        }
        return false;
    }
};