class Solution {
    int mini,sum;
    vector<int> prefix;
    vector<int> prep;
    int mod = 1e9 + 7;
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        prefix.resize(n+1,0);
        prep.resize(n+2,0);
        for (int i = 0;i<n;i++) {
            mini = min(mini,nums[i]);
            sum += nums[i];
            prefix[i+1] = prefix[i] + nums[i];
            prep[i+2] = prep[i+1] + prefix[i+1];
        }
        return smallestSum(nums,right)%mod - smallestSum(nums,left-1)%mod;
    }
    int smallestSum(vector<int>& nums,int k) {
        int left = mini, right = sum , ans = -1;
        pair<int,int> ansP;
        while (left <= right) {
            int mid = (left + right) / 2;
            pair<int,int> p = countL(nums,mid);
            if (p.first >= k) {
                ansP = p; ans = mid; right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return ansP.second - (ansP.first - k)*ans;
    }
    pair<int,int> countL(vector<int>& nums,int target) {
        int left = 0, right = 0, n =  nums.size(), sum = 0, total = 0, count = 0;
        while (right < n) {
            sum += nums[right];
            while (left <= right && sum>target) {
                sum -= nums[left]; left++;
            }
            int len = right - left +1;
            count += len;
            total = ((total+ (len*prefix[right+1]) - (prep[right+1] - prep[left])))%mod; right++;
        }
        pair<int,int> ans;
        ans.first = count; ans.second = total;
        return ans;
    }
};