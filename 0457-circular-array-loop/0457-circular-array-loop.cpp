class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0;i<n;i++) {
            if (nums[i] == 0) continue;
            bool d;
            if (nums[i] > 0) d = true;
            else d = false;
            int s = i, f = i;
            while (true) {
                int nextS = next(nums,s);
                int nextF = next(nums,f);
                int nextF2 = next(nums,nextF);

                if (d) {
                    if (nums[nextS] < 0 || nums[nextF] < 0 || nums[nextF2] < 0) break; 
                } else {
                    if (nums[nextS] > 0 || nums[nextF] > 0 || nums[nextF2] > 0) break; 
                }
                s = nextS;
                f = nextF2;
                if (s == f) {
                    if (s == next(nums,s)) break;
                    return true;
                }
            }
            int cur = i;
            while ((nums[cur] > 0 && d) || (nums[cur] < 0 && !d)) {
                int nxt = next(nums,cur);
                nums[cur] = 0;
                cur = nxt;
            }
        }
        return false;
    }
    int next(vector<int>& nums,int i) {
        int n = nums.size();
        return ((i+nums[i])%n + n)%n;
    }
};