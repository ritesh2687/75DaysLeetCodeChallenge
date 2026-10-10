class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        map<int, long long, greater<int>> diffCount;
        
        for (int i = 0; i < n; i++) {
            diffCount[abs(nums1[i] - nums2[i])]++;
        }
        
        long long totalOps = (long long)k1 + k2;
        
        while (totalOps > 0 && !diffCount.empty()) {
            auto it = diffCount.begin();
            int val = it->first;
            if (val == 0) break;
            
            long long count = it->second;
            auto nextIt = next(it);
            int nextVal = (nextIt == diffCount.end()) ? 0 : nextIt->first;
            
            long long diff = val - nextVal;
            long long totalCanReduce = diff * count;
            
            if (totalOps >= totalCanReduce) {
                totalOps -= totalCanReduce;
                diffCount[nextVal] += count;
                diffCount.erase(it);
            } else {
                long long steps = totalOps / count;
                long long remainder = totalOps % count;
                
                diffCount.erase(it);
                if (val - steps > 0) {
                    diffCount[val - steps] += count - remainder;
                }
                if (val - steps - 1 > 0) {
                    diffCount[val - steps - 1] += remainder;
                }
                totalOps = 0;
            }
        }
        
        long long sum = 0;
        for (auto& [val, count] : diffCount) {
            sum += (long long)val * val * count;
        }
        
        return sum;
    }
};