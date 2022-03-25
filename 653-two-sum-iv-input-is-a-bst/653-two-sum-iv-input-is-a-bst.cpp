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
    unordered_map<int , int> mpp;
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL){
            return false;
        }
        if(mpp.count(k - root->val)){
            return true;
        }else{
            mpp[root->val]++;
        }
        bool lt = findTarget(root->left , k);
        bool rt = findTarget(root->right , k);
        if(lt || rt){
            return true;
        }
        return false;
    }
};