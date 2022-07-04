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
    bool solve(TreeNode* path1 , TreeNode* path2){
        if(path1 == NULL && path2 == NULL){
            return true;
        }
        if(path1 == NULL || path2 == NULL){
            return false;
        }
        if(path1->val != path2->val){
            return false;
        }
        if(solve(path1->left , path2->right) && solve(path1->right , path2->left)){
            return true;
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return solve(root , root);
    }
};