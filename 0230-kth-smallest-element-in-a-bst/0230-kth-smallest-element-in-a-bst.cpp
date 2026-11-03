class Solution {
public:
    int dfs(TreeNode* curr, int &k) {
        if (curr == NULL) return -1;
        int left = dfs(curr->left, k);
        if (left != -1) return left;
        k--;
        if (k == 0) return curr->val;
        return dfs(curr->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        return dfs(root, k);
    }
};