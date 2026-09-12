class Solution {
public:
    struct State {
        long long score;
        vector<int> ids;
        bool operator<(const State& other) const {
            if (score != other.score) return score < other.score;
            return ids > other.ids;
        }
    };

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        struct Interval {
            long long l, r, w;
            int id;
        };
        vector<Interval> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        sort(arr.begin(), arr.end(), [](const Interval& a, const Interval& b) {
            if (a.r != b.r) return a.r < b.r;
            return a.l < b.l;
        });

        vector<long long> R(n);
        for (int i = 0; i < n; ++i) R[i] = arr[i].r;

        vector<vector<State>> dp(5, vector<State>(n + 1, {0, {}}));

        for (int k = 1; k <= 4; ++k) {
            for (int i = 1; i <= n; ++i) {
                State skip = dp[k][i - 1];
                
                auto it = lower_bound(R.begin(), R.end(), arr[i - 1].l);
                int j = distance(R.begin(), it);
                
                State take = dp[k - 1][j];
                take.score += arr[i - 1].w;
                take.ids.push_back(arr[i - 1].id);
                sort(take.ids.begin(), take.ids.end());

                dp[k][i] = max(skip, take);
            }
        }

        return dp[4][n].ids;
    }
};