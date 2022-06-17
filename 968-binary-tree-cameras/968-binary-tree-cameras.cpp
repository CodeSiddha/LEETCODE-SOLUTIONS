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
    int ans = 0;
    int solve(TreeNode* root){
        if(root == NULL){
            return 1;
        }
        
        int l = solve(root->left);
        int r = solve(root->right);
        
        if(l == -1 || r == -1){
            ans++;
            return 0; // have a camera.
        }
        if(l == 0 || r == 0){
            return 1; // covered.
        }
        return -1; // need a camera.
    }
    int minCameraCover(TreeNode* root) {
        if(solve(root) == -1) ans++;
        return ans;
    }
};