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
    int solve(TreeNode* root , int &tilt ){
        if(root == NULL){
            return 0;
        }
        int ls = 0;
        int rs = 0;
        ls = solve(root->left , tilt);
        rs = solve(root->right , tilt);
        tilt += abs(ls - rs);
        return  root->val + ls + rs;
    }
    int findTilt(TreeNode* root) {
        int tilt = 0;
        solve(root , tilt);
        return tilt; 
    }
};