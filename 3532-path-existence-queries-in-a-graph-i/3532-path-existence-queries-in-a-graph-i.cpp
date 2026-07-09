class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
    vector<int> component(n, 0);
        int current_id = 0;
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                current_id++;
            }
            component[i] = current_id;
        }
        
        vector<bool> answer;
        answer.reserve(queries.size());
        
        for (const auto& query : queries) {
            answer.push_back(component[query[0]] == component[query[1]]);
        }
        
        return answer;
    }
};