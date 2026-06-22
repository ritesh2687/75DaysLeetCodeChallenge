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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP;
        path(root, p, pathP);
        vector<TreeNode*> pathQ;
        path(root, q, pathQ);
        TreeNode* ans = nullptr;
        int i = 0;
        while (i < pathP.size() && i < pathQ.size() && pathP[i] == pathQ[i]) {
            ans = pathP[i];
            i++;
        }
        return ans;
    }
    bool path(TreeNode* root, TreeNode* target, vector<TreeNode*>& curr) {
        if (root == nullptr)
            return false;

        curr.push_back(root);
        if (root == target) {
            return true;
        }

        if (path(root->left, target, curr) || path(root->right, target, curr))
            return true;

        curr.pop_back();
        return false;
    }
};