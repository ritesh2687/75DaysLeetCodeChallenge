class Solution {
public:
static constexpr int INF = 1e6 + 1;
    static constexpr int N = 24;
    int C[N][N] = {{0}};

    void initPascal() {
        if (C[0][0] == 1) return;
        C[0][0] = 1;
        for (int i = 1; i < N; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j <= i / 2; j++) {
                C[i][j] = C[i][i - j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }

    int comb(int n, int k) {
        if (k < 0 || k > n) return 0;
        if (n < N) return C[n][k];
        if (2 * k > n) k = n - k;
        long long ans = 1;
        for (int i = 1; i <= k; i++) {
            ans = ans * (n - i + 1) / i;
            if (ans >= INF) return INF;
        }
        return ans;
    }

    int perm(const array<int, 26>& freq, int sz) {
        long long ans = 1;
        for (int f : freq) {
            if (f == 0) continue;
            ans *= comb(sz, f);
            if (ans >= INF) return INF;
            sz -= f;
        }
        return ans;
    }
    string smallestPalindrome(string s, int k) {
    initPascal();
        int n = s.size();
        int half = n / 2;

        array<int, 26> freq = {0};
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }

        char mid_char = 0;
        for (int c = 0; c < 26; c++) {
            if (freq[c] % 2 != 0) {
                mid_char = 'a' + c;
            }
            freq[c] /= 2;
        }

        int total = perm(freq, half);
        if (k > total) return "";

        string left = "";
        left.reserve(half);
        int sz = half;

        for (int i = 0; i < half; i++) {
            for (int c = 0; c < 26; c++) {
                if (freq[c] == 0) continue;

                freq[c]--;
                int count = perm(freq, sz - 1);

                if (count >= k) {
                    left.push_back('a' + c);
                    sz--;
                    break;
                } else {
                    k -= count;
                    freq[c]++;
                }
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (n % 2 != 0) {
            left.push_back(mid_char);
        }
        left.append(right);

        return left;
    }
};