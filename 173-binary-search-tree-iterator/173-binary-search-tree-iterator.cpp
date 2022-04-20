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
class BSTIterator {
    private:
    vector<int> inorder;
    int idx;
public:
    void fill(TreeNode* root){
        if(root == NULL){
            return ;
        }
        fill(root->left);
        inorder.push_back(root->val);
        fill(root->right);
        return;
    }
    BSTIterator(TreeNode* root) {
        idx = -1;
        fill(root);
    }
    
    int next() {
        ++idx;
        return inorder[idx];
    }
    
    bool hasNext() {
        return (idx == inorder.size() - 1 ? false : true);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */