class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;

        int l = 0, r = 0;
        TreeNode* temp = root;

        while(temp) {
            l++;
            temp = temp->left;
        }

        temp = root;

        while(temp) {
            r++;
            temp = temp->right;
        }

        if(l == r) {
            return (1 << l) - 1;
        }

        return 1 + countNodes(root->left)
                 + countNodes(root->right);
    }
};