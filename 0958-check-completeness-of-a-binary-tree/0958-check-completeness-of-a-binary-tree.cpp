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
    int countNode(TreeNode* root){
        if(!root) return 0;
        return 1 + countNode(root->left) + countNode(root->right);

        
    }
    bool dfs(TreeNode* node , int idx,int n){
        if(!node) return true;
        if(idx >= n) return false;
        return dfs(node-> left, 2 * idx + 1, n) && dfs(node->right , 2 * idx + 2, n); 
    }

    bool isCompleteTree(TreeNode* root) {
        
        int n = countNode(root);
        return dfs(root, 0 ,n);
    }
};