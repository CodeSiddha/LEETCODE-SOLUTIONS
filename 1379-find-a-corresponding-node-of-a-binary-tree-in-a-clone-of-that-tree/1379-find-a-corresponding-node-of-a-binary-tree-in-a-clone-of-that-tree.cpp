/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original == NULL){
            return NULL;
        }
        queue<TreeNode*> que1 , que2;
        que1.push(original);
        que2.push(cloned);
        while(!que1.empty() && !que2.empty()){
            int level = que1.size();
            for(int i = 0 ; i < level ; i++){
                TreeNode* top1 = que1.front();
                TreeNode* top2 = que2.front();
                if(top1 == target){
                    return top2;
                }
                if(top1->left) que1.push(top1->left);
                if(top1->right) que1.push(top1->right);
                if(top2->left) que2.push(top2->left);
                if(top2->right) que2.push(top2->right);
                que1.pop();
                que2.pop();
            }
            
        }
        return NULL;
    }
};