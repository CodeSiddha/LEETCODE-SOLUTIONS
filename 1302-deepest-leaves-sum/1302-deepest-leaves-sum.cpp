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
    int findh(TreeNode* root){
        if(root == NULL){
            return -1;
        }
        int lh = findh(root->left);
        int rh = findh(root->right);
        int mh = max(lh , rh) + 1;
        return mh;
    }
    int findDeepSum(TreeNode* root , int Deep , int &ans){
        if(root == NULL){
            return 0;
        }
        if(Deep == 0){
            ans += root->val;
        }
        int lt = findDeepSum(root->left , Deep - 1, ans);        
        int rt = findDeepSum(root->right , Deep - 1, ans);
        return ans;
    }
    int deepestLeavesSum(TreeNode* root) {
        int height = findh(root);
        int res = 0;
        return findDeepSum(root , height , res);
    }
};