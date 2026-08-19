class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rowMasks;
        
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            if (col >= 2 && col <= 9) {
                rowMasks[row] |= (1 << col);
            }
        }
        
        int count = (n - rowMasks.size()) * 2;
        
        int leftMask = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int rightMask = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);
        int middleMask = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        
        for (const auto& [row, mask] : rowMasks) {
            bool left = (mask & leftMask) == 0;
            bool right = (mask & rightMask) == 0;
            
            if (left && right) {
                count += 2;
            } else if (left || right || (mask & middleMask) == 0) {
                count += 1;
            }
        }
        
        return count;
    }
};