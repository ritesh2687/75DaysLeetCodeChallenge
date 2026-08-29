#include <vector>
#include <algorithm>
#include <unordered_map>
#include <deque>

class Solution {
public:
    std::vector<int> lexicographicallySmallestArray(std::vector<int>& nums, int limit) {
        int n = nums.size();
        std::vector<std::pair<int, int>> sorted_nums(n);
        for (int i = 0; i < n; ++i) {
            sorted_nums[i] = {nums[i], i};
        }
        
        std::sort(sorted_nums.begin(), sorted_nums.end());
        
        std::vector<std::deque<int>> groups;
        std::unordered_map<int, int> num_to_group;
        
        int group_idx = 0;
        groups.push_back({sorted_nums[0].first});
        num_to_group[sorted_nums[0].first] = group_idx;
        
        for (int i = 1; i < n; ++i) {
            if (sorted_nums[i].first - sorted_nums[i - 1].first > limit) {
                group_idx++;
                groups.push_back({});
            }
            groups[group_idx].push_back(sorted_nums[i].first);
            num_to_group[sorted_nums[i].first] = group_idx;
        }
        
        std::vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            int g_idx = num_to_group[nums[i]];
            result[i] = groups[g_idx].front();
            groups[g_idx].pop_front();
        }
        
        return result;
    }
};