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
    pair<int , int> solve(TreeNode* root){
        if(root == NULL){
            pair<int ,int> mp;
            mp.first = -1;
            mp.second = 0;
            return mp;
        }
        pair<int , int> lp = solve(root->left);
        pair<int, int> rp = solve(root->right);
        pair<int , int> mp;
        mp.first = max(lp.first , rp.first) + 1;
        int pvr = lp.first + rp.first + 2;  //pvr :- path via root.
        mp.second = max({pvr, lp.second , rp.second});
        return mp;
    }
    int diameterOfBinaryTree(TreeNode* root) {
      
        pair<int , int> ans = solve(root);
        return ans.second;
    }
};