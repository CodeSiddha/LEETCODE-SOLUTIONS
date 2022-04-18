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
    void solve(TreeNode* root , int k , int kth , vector<int> &ans){
        if(root == NULL){
            return;
        }
        solve(root->left , k , kth , ans);
        if(ans.size() == k){
            return;
        }
        ans.push_back(root->val);
        solve(root->right , k , kth, ans);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        solve(root , k , 0 , ans);
        return ans.back();
    }
};