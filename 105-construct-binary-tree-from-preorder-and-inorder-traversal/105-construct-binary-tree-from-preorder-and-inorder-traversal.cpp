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
    int inSearch(vector<int>&inorder , int inStart ,int inEnd , int val){
        int idx = 0;
        for(int i = inStart ; i <= inEnd ; i++){
            if(inorder[i] == val){
                idx = i;
                break;
            }
        }
        return idx;
    }
    int pre = 0;
    TreeNode* MakeBinaryTree(vector<int>&preorder , vector<int>&inorder , int inStart , int inEnd){
        if(inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[pre++]);
        if(inStart == inEnd) return root;
        int search = inSearch(inorder , inStart , inEnd , root->val);
        root->left = MakeBinaryTree(preorder , inorder , inStart , search - 1);
        root->right = MakeBinaryTree(preorder , inorder , search + 1 , inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        TreeNode* root = MakeBinaryTree(preorder , inorder , 0 , n - 1);
        return root;
    }
};