class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> sorted_nums(n);
        for (int i = 0; i < n; ++i) {
            sorted_nums[i] = {nums[i], i};
        }
        
        sort(sorted_nums.begin(), sorted_nums.end());
        
        vector<vector<int>> group_vals;
        vector<vector<int>> group_indices;
        
        for (int i = 0; i < n; ++i) {
            if (group_vals.empty() || sorted_nums[i].first - group_vals.back().back() > limit) {
                group_vals.push_back({sorted_nums[i].first});
                group_indices.push_back({sorted_nums[i].second});
            } else {
                group_vals.back().push_back(sorted_nums[i].first);
                group_indices.back().push_back(sorted_nums[i].second);
            }
        }
        
        vector<int> result(n);
        for (size_t i = 0; i < group_vals.size(); ++i) {
            auto& indices = group_indices[i];
            auto& vals = group_vals[i];
            
            sort(indices.begin(), indices.end());
            
            for (size_t j = 0; j < indices.size(); ++j) {
                result[indices[j]] = vals[j];
            }
        }
        
        return result;
    }
};