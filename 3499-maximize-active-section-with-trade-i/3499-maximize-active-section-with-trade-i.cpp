class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int i = 0, lz = 0, curr = 0, maxi = 0, one = 0;
        while (i<n && s[i] == '1') one++, i++;
        while (i<n && s[i] == '0') lz++, i++;

        while (i<n) {
            while (i<n && s[i] == '1') one++, i++;
            if (i == n) return one + maxi;
            while (i<n && s[i] == '0') curr++, i++;
            maxi = max(maxi,curr+lz);
            lz = curr;
            curr = 0;
        }
        return one + maxi;
    }
};