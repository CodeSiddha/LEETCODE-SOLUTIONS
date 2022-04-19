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
    void solve1(TreeNode* root , TreeNode* &small , bool &found){
        if(root == NULL){
            return;
        }
        solve1(root->right , small , found);
        if(!found){
            if(small == NULL){
                small = root;
            }else if(small->val > root->val){
                small = root;
            }else{
                found = true;
            }
        }
        solve1(root->left , small , found);
        return;
    }
    void solve2(TreeNode* root , TreeNode* &big , bool &found){
        if(root == NULL){
            return;
        }
        solve2(root->left , big , found);
        if(!found){
            if(big == NULL){
                big = root;
                // cout << big->val << endl;
            }else if(big->val < root->val){
                big = root;
            }else{
                found = true;
            }
        }
        solve2(root->right , big , found);
        return;
    }
    void recoverTree(TreeNode* root) {
        TreeNode* small , *big;
        small = big = NULL;
        bool found = false;
        solve1(root , small , found);
        found = false;
        solve2(root , big , found);
        // cout << small->val << " " << big->val << endl;
        swap(small->val  , big->val);
        return;
    }
};