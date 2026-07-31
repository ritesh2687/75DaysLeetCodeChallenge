class Solution {
public:
    TreeNode* prev = nullptr;
    int ans = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        dfs(root->left);
        if (prev != nullptr) {
            ans = min(ans,root->val - prev->val);
        }
        prev = root;
        dfs(root->right);
    }
};