class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;

        auto bfs = [&](int start_r, int start_c) {
            long long total_value = 0;
            queue<pair<int, int>> q;
            q.push({start_r, start_c});
            visited[start_r][start_c] = true;

            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};

            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();
                total_value += grid[r][c];

                for (int i = 0; i < 4; ++i) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] && grid[nr][nc] > 0) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }

            if (total_value % k == 0) {
                count++;
            }
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0 && !visited[i][j]) {
                    bfs(i, j);
                }
            }
        }

        return count;
    }
};