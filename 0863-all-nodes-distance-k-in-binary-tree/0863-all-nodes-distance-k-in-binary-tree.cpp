/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<vector<int>> adj;
    vector<int> answer;
    int k;
public:
    void dfs(int node,int dis,int parent) {

        if (dis == k) {
            answer.push_back(node);
            return;
        }
        for (int next : adj[node]) {
            if (next == parent) continue;
            dfs(next,dis+1,node);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        this->k = k;
        adj.resize(501,vector<int>());
        dfs(root,nullptr);
        dfs(target->val,0,-1);
        return answer;
    }
    void dfs(TreeNode* root,TreeNode* parent) {
        if (root == nullptr) return;

        int u = root->val;
        if (parent != nullptr) {
            int v = parent->val;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(root->left, root);
        dfs(root->right, root);
    }
};