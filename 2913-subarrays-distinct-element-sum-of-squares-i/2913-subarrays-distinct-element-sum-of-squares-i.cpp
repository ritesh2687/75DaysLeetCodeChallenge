class Solution {
public:
    int sumCounts(vector<int>& arr) {
    int n = arr.size();
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        std::unordered_set<int> s;
        for (int j = i; j < n; j++) {
            s.insert(arr[j]);
            long long cnt = s.size();
            ans += (cnt * cnt);
        }
    }
    return ans;
}
};