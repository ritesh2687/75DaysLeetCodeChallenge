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
    int sum=INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return sum;
    }
    
    int dfs(TreeNode* root){
        if(root==nullptr) return 0;
        int left=dfs(root->left);
        left=left<0? 0: left;
        int right=dfs(root->right);
        right=right<0? 0:right;
        sum=max(sum,root->val+left+right);
        
        return root->val +max(left,right);
    }
};