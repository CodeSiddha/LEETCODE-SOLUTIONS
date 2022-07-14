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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int level = que.size();
            vector<int> temp;
            for(int i = 1 ; i <= level ; i++){
                auto top = que.front();
                que.pop();
                temp.push_back(top->val);
                if(top->left) que.push(top->left);
                if(top->right) que.push(top->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};