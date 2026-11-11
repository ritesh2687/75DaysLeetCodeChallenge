class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1, c2 = cost2, cb = costBoth;
        long long n1 = need1, n2 = need2;

        cb = min(cb, c1 + c2);
        
        long long shared = min(n1, n2);
        long long total = shared * cb;
        
        n1 -= shared;
        n2 -= shared;

        total += n1 * min(c1, cb);
        total += n2 * min(c2, cb);

        return total;
    }
};