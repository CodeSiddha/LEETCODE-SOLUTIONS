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
    TreeNode* solve(TreeNode* root){
        if(root == NULL) return NULL;
        TreeNode* L = solve(root->left);
        TreeNode* R = solve(root->right);
        if(L != NULL && R != NULL){
            root->right = L;
            TreeNode* temp = L;
            while(temp->right != NULL){
                temp = temp -> right;
            }
            temp->right = R;
            root->left = NULL;
        }else if(L != NULL && R == NULL){
            root->right = L;
            root->left = NULL;
        }
        return root;
    }
    void flatten(TreeNode* root) {
        solve(root);
    }
};