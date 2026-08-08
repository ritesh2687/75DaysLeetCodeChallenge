class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> last_pos(m, -1);
        
        int j = m - 1;
        for (int i = n - 1; i >= 0 && j >= 0; i--) {
            if (word1[i] == word2[j]) {
                last_pos[j] = i;
                j--;
            }
        }

        vector<int> ans;
        bool changed = false;
        j = 0;

        for (int i = 0; i < n && j < m; i++) {
            bool can_change = !changed && (j == m - 1 || i < last_pos[j + 1]);
            
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            } else if (can_change) {
                ans.push_back(i);
                changed = true;
                j++;
            }
        }

        return ans.size() == m ? ans : vector<int>();
    }
};