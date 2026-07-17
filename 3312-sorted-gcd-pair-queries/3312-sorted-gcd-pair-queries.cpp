class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        unordered_map<int,int> map;
        int maxi = 0;
        for (int x : nums) map[x]++, maxi = max(maxi,x);
        vector<int> freq(maxi+1,0);
        for (int i = maxi;i>=1;i--) {
            long long count = map[i];
            int sum = 0;
            for (int j = 2*i;j<=maxi;j+=i) {
                
                count += map[j];
                sum += freq[j];
            }
            count = (count-1)*count / 2;
            freq[i] = count - sum;
        }
        for (int i = 1;i<=maxi;i++) freq[i] = freq[i-1] + freq[i]; 
        int n = queries.size();
        vector<int> ans(n);
        for (int i = 0;i<n;i++) {
            int q = queries[i];
            int res = -1, l = 1, r = maxi;
            while (l <= r) {
                int mid = (l+r) / 2;
                if (freq[mid]>=q+1) {
                    res = mid;
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            }
            ans[i] = res;
        }
        return ans;
    }
};