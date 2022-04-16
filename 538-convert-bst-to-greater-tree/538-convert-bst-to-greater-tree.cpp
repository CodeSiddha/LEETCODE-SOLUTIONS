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
    void solve(TreeNode* root , int &currSum){
        if(root == NULL){
            return;
        }
        solve(root->right , currSum);
        currSum += root->val;
        root->val = currSum;
        solve(root->left , currSum);
        return;
    }
    TreeNode* convertBST(TreeNode* root) {
        int currSum = 0;
        solve(root , currSum);
        return root;
    }
};