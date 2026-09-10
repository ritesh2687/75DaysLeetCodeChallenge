class Solution {
public:

    int sum(TreeNode* root) {
        if (root == nullptr)
            return 0;

        return root->val + sum(root->left) + sum(root->right);
    }

    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int average(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int totalSum = sum(root);
        int totalNodes = countNodes(root);

        return totalSum / totalNodes;
    }

    int averageOfSubtree(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int count = 0;

        if (root->val == average(root))
            count++;

        count += averageOfSubtree(root->left);
        count += averageOfSubtree(root->right);

        return count;
    }
};