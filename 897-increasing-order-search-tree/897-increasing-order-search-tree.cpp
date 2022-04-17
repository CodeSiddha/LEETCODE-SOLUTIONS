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
    void fillque(TreeNode* root , queue<TreeNode*>&que){
        if(root == NULL){
            return;
        }
        fillque(root->left , que);
        que.push(root);
        fillque(root->right , que);
        return;
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        queue<TreeNode*> que;
        fillque(root , que);
        TreeNode* head = que.front();
        while(!que.empty()){
            TreeNode* top = que.front();
            que.pop();
            top->left = NULL;
            if(que.empty()){
                top->right = NULL;
            }else{
                top->right = que.front();
            }
        }
        return head;
    }
};