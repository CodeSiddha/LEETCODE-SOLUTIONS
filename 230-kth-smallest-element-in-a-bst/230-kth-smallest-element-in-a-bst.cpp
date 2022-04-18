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
    void solve(TreeNode* root , int k , pair<int ,int> &ans){
        if(root == NULL){
            return;
        }
        solve(root->left , k , ans);
        if(ans.second == k){
            return;
        }
        ans.first = root->val;
        ans.second++;
        solve(root->right , k , ans);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        pair<int ,int> ans = {-1 , 0};
        solve(root , k , ans);
        return ans.first;
    }
};