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
    private:
    int min = 1e5;
    int prev = -1;
public:
    int getMinimumDifference(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        getMinimumDifference(root->left);
        if(prev == -1){
            prev = root->val;
        }else{
            min = std::min(min , root->val - prev);
            prev = root->val;
        }
        getMinimumDifference(root->right);
        return min;
        
    }
};