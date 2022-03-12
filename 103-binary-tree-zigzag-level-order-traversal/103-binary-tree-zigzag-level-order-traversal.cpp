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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        queue<TreeNode*> que;
        que.push(root);
        bool forward = true;
        while(!que.empty()){
            int level = que.size();
            vector<int> temp;
              for(int i = 1 ; i <=level ; i++){
                  TreeNode* top = que.front();
                  temp.push_back(top->val);
                  if(top->left) que.push(top->left);
                  if(top->right) que.push(top->right);
                  que.pop();
              }
            if(!forward){
                reverse(temp.begin() , temp.end());
            }
            forward = !forward;
            ans.push_back(temp);
        }
        return ans;
    }
};