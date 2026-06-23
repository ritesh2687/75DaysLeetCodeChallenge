/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    unordered_map<TreeNode*,int> height;
    unordered_map<int,int> answer;
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfs(root);
        dfs(root,-1,0);
        vector<int> ans;
        // for  (auto it : height) {
        //     cout << it.first->val << " " << it.second << endl;
        // }
        for (int x : queries) {
            ans.push_back(answer[x]);
        }
        return ans;
    }
    void dfs(TreeNode* root,int k,int maxi) {
        if (root == nullptr) return;
        int l = (root->left != nullptr) ? height[root->left] : 0;
        int r = (root->right != nullptr) ? height[root->right] : 0;
        answer[root->val] = maxi;
        if (root->left != nullptr) {
            int nH = r + k + 1;
            dfs(root->left,k+1,max(maxi,nH));
        } 
        if (root->right != nullptr) {
            int nH = l + k + 1;
            dfs(root->right,k+1,max(maxi,nH));
        }
    }
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        height[root] = max(l,r)+1;
        return height[root];
    }
};