class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long oddCount = 0;
        long long evenCount = 1;
        long long prefixSum = 0;
        long long result = 0;

        for (int num : arr) {
            prefixSum += num;
            if (prefixSum % 2 == 1) {
                result = (result + evenCount) % MOD;
                oddCount++;
            } else {
                result = (result + oddCount) % MOD;
                evenCount++;
            }
        }

        return result;
    }
};