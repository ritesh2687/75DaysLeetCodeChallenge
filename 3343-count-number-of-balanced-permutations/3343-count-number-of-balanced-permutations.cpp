class Solution {
    vector<int> count;
    vector<long long> fact;
    vector<long long> invFact;
    int mod = 1e9 + 7;
    vector<vector<vector<long long>>> dp;
public:
    long long power(int base,int exp) {
        if (exp == 0) return 1;

        long long half = power(base, exp/2);
        long long ans = half * half % mod;

        if (exp % 2 == 0) {
            return ans;
        } else {
            return ans * base % mod;
        }
    }


    long long comb(int n,int k) {
        return (long long)fact[n] * invFact[k] % mod * invFact[n-k] % mod;
    }

    long long dfs(int digit,int sumR,int evenR) {
        if (sumR<0) return 0;
        if (digit == 10) {
            if  (sumR == 0 && evenR == 0) return 1;
            return 0;
        }
        if (dp[digit][sumR][evenR] != -1) return dp[digit][sumR][evenR];
        long long ans = 0;
        for (int freq = 0; freq <= min(evenR,count[digit]);freq++) {

            ans = (ans + comb(count[digit],freq) % mod * dfs(digit+1,sumR - freq*digit,evenR-freq)) % mod;

        }
        return dp[digit][sumR][evenR] = ans;
    }
    int countBalancedPermutations(string num) {

        int n = num.size();
        int total = 0;

        count.resize(10,0);
        fact.resize(n+1);
        invFact.resize(n+1);

        int evenLen = (n+1) / 2;
        int oddLen = n/2;
        for (char c : num) {
            int digit = c - '0';
            count[digit]++;
            total += digit;
        }
        // int[10][target+1][evenLen]

        if (total % 2== 1) return 0;
        int target = total / 2;

        dp.resize(
            10,
            vector<vector<long long>>(
                target+1,
                vector<long long>(
                    evenLen+1,
                    -1
                )
            )
        );

        fact[0] = 1;
        for (int i = 1;i<=n;i++) fact[i] = fact[i-1] * i % mod;

        invFact[n] = power(fact[n], mod -2);

        for (int i =  n-1;i>=0;i--) invFact[i] = invFact[i+1] * (i+1) % mod;

        long long answer = dfs(0,target,evenLen);

        for (int i = 0;i<10;i++) {
            answer = (answer * invFact[count[i]]) % mod;
        }

        answer = answer * fact[evenLen] % mod;
        answer = answer * fact[oddLen] % mod;
        return answer;
    }
};