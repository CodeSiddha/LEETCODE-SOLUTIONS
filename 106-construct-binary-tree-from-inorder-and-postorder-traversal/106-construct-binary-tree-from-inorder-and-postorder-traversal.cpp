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
    int search(vector<int>&inorder , int start , int end , int val){
        int i = start;
        for(i = start ; i <= end ; i++){
            if(val == inorder[i]){
                 break;
            }
        }
        return i;
    }
    int po;
    TreeNode* MakeBinaryTree(vector<int>&in , vector<int>&post , int istart , int iend){
        if(istart > iend){
            return NULL;
        }
        TreeNode* root = new TreeNode(post[po--]);
        if(istart == iend){
            return root;
        }
        int Insearch = search(in , istart , iend , root->val);//
        root->right = MakeBinaryTree(in , post , Insearch + 1 , iend);
        root->left = MakeBinaryTree(in , post , istart , Insearch - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        po = postorder.size() - 1;
        int istart = 0;
        int iend = inorder.size() - 1;
        TreeNode* root = MakeBinaryTree(inorder , postorder , istart , iend);
        return root;
    }
};