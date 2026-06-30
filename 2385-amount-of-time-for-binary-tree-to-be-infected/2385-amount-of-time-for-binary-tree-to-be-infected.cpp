class Solution {
    vector<vector<int>> adj;
public:
    int amountOfTime(TreeNode* root, int start) {
        int maxi = dfs(root);
        adj.resize(maxi+1,vector<int>());
        dfs(root,nullptr);
        int depth = -1;
        queue<pair<int,int>> q;
        q.push({start,-1});
        while (q.size() != 0) {
            int size = q.size();
            depth++;
            for (int i = 0;i<size;i++) {
                auto [node,parent] = q.front(); q.pop();
                for (int next : adj[node]) {
                    if (next == parent) continue;
                    q.push({next,node});
                }
            }
        }
        return depth;
    }
    void dfs(TreeNode* root,TreeNode* parent) {
        if (root == nullptr) return;

        if (parent != nullptr) adj[root->val].push_back(parent->val);
        if (root->left != nullptr) {
            adj[root->val].push_back(root->left->val);
            dfs(root->left,root);
        }
        if (root->right != nullptr) {
            adj[root->val].push_back(root
            ->right->val);
            dfs(root->right,root);
        }
    }
    int dfs(TreeNode* root) {
        if (root == nullptr) return INT_MIN;
        int left = dfs(root->left);
        int right = dfs(root->right);
        return max({left,right,root->val});
    }
};