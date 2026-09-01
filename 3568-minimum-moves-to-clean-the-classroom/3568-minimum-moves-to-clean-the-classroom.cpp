#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int startX = -1, startY = -1;
        vector<pair<int, int>> litters;
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (classroom[r][c] == 'S') {
                    startX = r;
                    startY = c;
                } else if (classroom[r][c] == 'L') {
                    litters.push_back({r, c});
                }
            }
        }
        
        int totalLitters = litters.size();
        int targetMask = (1 << totalLitters) - 1;
        
        if (targetMask == 0) return 0;
        
        vector<vector<vector<int>>> bestEnergy(m, vector<vector<int>>(n, vector<int>(1 << totalLitters, -1)));
        queue<tuple<int, int, int, int, int>> q;
        
        q.push({startX, startY, 0, energy, 0});
        bestEnergy[startX][startY][0] = energy;
        
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            auto [r, c, mask, curEnergy, moves] = q.front();
            q.pop();
            
            if (mask == targetMask) {
                return moves;
            }
            
            if (curEnergy == 0) continue;
            
            for (auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || classroom[nr][nc] == 'X') {
                    continue;
                }
                
                int nextMask = mask;
                char cell = classroom[nr][nc];
                
                if (cell == 'L') {
                    for (int i = 0; i < totalLitters; ++i) {
                        if (litters[i].first == nr && litters[i].second == nc) {
                            nextMask |= (1 << i);
                            break;
                        }
                    }
                }
                
                int nextEnergy = curEnergy - 1;
                if (cell == 'R') {
                    nextEnergy = energy;
                }
                
                if (nextEnergy > bestEnergy[nr][nc][nextMask]) {
                    bestEnergy[nr][nc][nextMask] = nextEnergy;
                    q.push({nr, nc, nextMask, nextEnergy, moves + 1});
                }
            }
        }
        
        return -1;
    }
};