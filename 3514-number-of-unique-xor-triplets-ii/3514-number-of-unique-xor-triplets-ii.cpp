class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
    int n = nums.size();
        
       
        std::vector<bool> seen_pair(2048, false);
        std::vector<bool> seen_triplet(2048, false);

        for (int i = n - 1; i >= 0; --i) {
            
            for (int j = i; j < n; ++j) {
                seen_pair[nums[i] ^ nums[j]] = true;
            }

            // Combine nums[i] with all known pair XORs (j >= i, k >= j)
            for (int val = 0; val < 2048; ++val) {
                if (seen_pair[val]) {
                    seen_triplet[nums[i] ^ val] = true;
                }
            }
        }

        // Count unique XOR triplet values
        int count = 0;
        for (bool present : seen_triplet) {
            if (present) {
                count++;
            }
        }

        return count;
    }
};