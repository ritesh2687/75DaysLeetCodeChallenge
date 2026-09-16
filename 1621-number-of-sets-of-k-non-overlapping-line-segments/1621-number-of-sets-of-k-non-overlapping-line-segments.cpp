class Solution {
    long long power(long long base, long long exp) {
        long long res = 1, mod = 1e9 + 7;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

public:
    int numberOfSets(int n, int k) {
        int N = n + k - 1;
        int K = 2 * k;
        if (N < K) return 0;
        
        long long num = 1, den = 1, mod = 1e9 + 7;
        for (int i = 1; i <= K; ++i) {
            num = (num * (N - i + 1)) % mod;
            den = (den * i) % mod;
        }
        
        return (num * power(den, mod - 2)) % mod;
    }
};