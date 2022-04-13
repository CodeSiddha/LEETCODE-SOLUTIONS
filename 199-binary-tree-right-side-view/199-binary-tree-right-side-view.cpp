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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int level = que.size();
            for(int i = 0 ; i < level ; i++){
                TreeNode* top = que.front();
                if(i == 0){
                    ans.push_back(top->val);
                }
                if(top->right) que.push(top->right);
                if(top->left) que.push(top->left);
                que.pop();
            }
        }
        return ans;
    }
};