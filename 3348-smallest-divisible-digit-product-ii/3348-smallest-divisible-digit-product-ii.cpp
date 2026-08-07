class Solution {
    int countFactors(long long t, int p) {
        int cnt = 0;
        while (t > 0 && t % p == 0) {
            cnt++;
            t /= p;
        }
        return cnt;
    }

    int getMinDigits(int c2, int c3, int c5, int c7) {
        int d8 = c2 / 3; c2 %= 3;
        int d9 = c3 / 2; c3 %= 2;
        int d4 = c2 / 2; c2 %= 2;
        int d6 = 0;
        if (c2 == 1 && c3 == 1) {
            d6 = 1; c2 = 0; c3 = 0;
        }
        return d8 + d9 + d4 + d6 + c2 + c3 + c5 + c7;
    }

    string constructDigits(int c2, int c3, int c5, int c7, int targetLen) {
        if (getMinDigits(c2, c3, c5, c7) > targetLen) return "";

        string res = "";
        for (int pos = 0; pos < targetLen; pos++) {
            int remLen = targetLen - 1 - pos;
            for (int d = 1; d <= 9; d++) {
                int nc2 = max(0, c2 - countFactors(d, 2));
                int nc3 = max(0, c3 - countFactors(d, 3));
                int nc5 = max(0, c5 - countFactors(d, 5));
                int nc7 = max(0, c7 - countFactors(d, 7));

                if (getMinDigits(nc2, nc3, nc5, nc7) <= remLen) {
                    res += to_string(d);
                    c2 = nc2; c3 = nc3; c5 = nc5; c7 = nc7;
                    break;
                }
            }
        }
        return res;
    }

public:
    string smallestNumber(string num, long long t) {
        long long temp = t;
        int c2 = countFactors(temp, 2);
        int c3 = countFactors(temp, 3);
        int c5 = countFactors(temp, 5);
        int c7 = countFactors(temp, 7);

        long long rem = temp;
        for (int i = 0; i < c2; i++) rem /= 2;
        for (int i = 0; i < c3; i++) rem /= 3;
        for (int i = 0; i < c5; i++) rem /= 5;
        for (int i = 0; i < c7; i++) rem /= 7;

        if (rem > 1) return "-1";

        int n = num.length();
        vector<int> req2(n + 1, 0), req3(n + 1, 0), req5(n + 1, 0), req7(n + 1, 0);
        req2[0] = c2; req3[0] = c3; req5[0] = c5; req7[0] = c7;

        int firstZero = -1;
        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                firstZero = i;
                break;
            }
            int d = num[i] - '0';
            req2[i + 1] = max(0, req2[i] - countFactors(d, 2));
            req3[i + 1] = max(0, req3[i] - countFactors(d, 3));
            req5[i + 1] = max(0, req5[i] - countFactors(d, 5));
            req7[i + 1] = max(0, req7[i] - countFactors(d, 7));
        }

        if (firstZero == -1 && req2[n] == 0 && req3[n] == 0 && req5[n] == 0 && req7[n] == 0) {
            return num;
        }

        int limit = (firstZero != -1) ? firstZero : n - 1;

        for (int i = limit; i >= 0; i--) {
            int startDigit = num[i] - '0' + 1;
            for (int d = startDigit; d <= 9; d++) {
                int r2 = max(0, req2[i] - countFactors(d, 2));
                int r3 = max(0, req3[i] - countFactors(d, 3));
                int r5 = max(0, req5[i] - countFactors(d, 5));
                int r7 = max(0, req7[i] - countFactors(d, 7));

                string tail = constructDigits(r2, r3, r5, r7, n - 1 - i);
                if (!tail.empty() || (n - 1 - i == 0 && r2 == 0 && r3 == 0 && r5 == 0 && r7 == 0)) {
                    string pref = num.substr(0, i);
                    pref += to_string(d);
                    return pref + tail;
                }
            }
        }

        for (int len = n + 1; ; len++) {
            string ans = constructDigits(c2, c3, c5, c7, len);
            if (!ans.empty()) return ans;
        }

        return "-1";
    }
};