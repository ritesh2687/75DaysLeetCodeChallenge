class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (root->val > key) {
            root->left = deleteNode(root->left,key);
            return root;
        } else if (root->val < key) {
            root->right = deleteNode(root->right,key); 
            return root;
        }
        if (root->left  == nullptr) return root->right;
        if (root->right == nullptr) return root->left;
        TreeNode* parent = root; TreeNode* temp = root->right;
        while (temp->left != nullptr) {
            parent = temp; temp = temp->left;
        }
        if (parent != root) {
            parent->left = temp->right;
            temp->right = root->right;
        }
        temp->left = root->left;
        return temp;
    }
};