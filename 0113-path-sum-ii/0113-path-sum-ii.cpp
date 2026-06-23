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
public:

    vector<vector<int>> answer;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> curr;
        backTrack(root,targetSum,vector<int>());

        return answer;
    }

    void backTrack(TreeNode*root,int sum,vector<int>curr){
         if(root==nullptr) return ;
         
        curr.push_back(root->val);
         
         if(root->left==nullptr && root->right ==nullptr){
            if(root->val ==sum){
            answer.push_back(curr);
            }             
         }
         else{
             backTrack(root->left,sum-root->val,curr);
            backTrack(root->right,sum-root->val,curr);
            
         }
         
         curr.pop_back();
    }
    
};