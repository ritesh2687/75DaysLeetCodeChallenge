class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int q = queries.size();
        vector<int> ans(q);
        vector<pair<int, int>> sortedQueries(q);
        for (int i = 0; i < q; ++i) {
            sortedQueries[i] = {queries[i], i};
        }
        
        sort(sortedQueries.begin(), sortedQueries.end());
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        unordered_map<int, int> cnt;
        int activeServers = 0;
        int left = 0, right = 0;
        int m = logs.size();

        for (int i = 0; i < q; ++i) {
            int queryTime = sortedQueries[i].first;
            int queryIdx = sortedQueries[i].second;
            int startTime = queryTime - x;

            while (right < m && logs[right][1] <= queryTime) {
                int server = logs[right][0];
                if (cnt[server] == 0) {
                    activeServers++;
                }
                cnt[server]++;
                right++;
            }

            while (left < m && logs[left][1] < startTime) {
                int server = logs[left][0];
                cnt[server]--;
                if (cnt[server] == 0) {
                    activeServers--;
                }
                left++;
            }

            ans[queryIdx] = n - activeServers;
        }

        return ans;
    }
};