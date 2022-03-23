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
    int solve(TreeNode* root ,bool &ans){
        if(root == NULL){
            return 0;
        }
        if(!ans){
            return 0;
        }
        int lh = solve(root->left , ans);
        int rh = solve(root->right , ans);
        int h = max(lh , rh) + 1;
        if(abs(lh - rh) > 1){
            ans = false;
        }
        return h;
    }
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        solve(root , ans);
        return ans;
    }
};