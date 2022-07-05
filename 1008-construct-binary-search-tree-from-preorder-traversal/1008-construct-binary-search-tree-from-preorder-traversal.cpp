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
    int search(vector<int>&preorder , int preStart , int preEnd , int val){
        int i;
        for(i = preStart ;i <= preEnd ; i++){
            if(val < preorder[i]){
                break;
            }
        }
        return i - 1;
    }
    int pre = 0;
    TreeNode* MakeBST(vector<int>&preorder , int preStart , int preEnd){
        if(preStart > preEnd){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);
        if(preStart == preEnd){
            return root;
        }
        int Insearch = search(preorder , preStart + 1 , preEnd , root->val);
        root->left = MakeBST(preorder , preStart + 1 , Insearch);
        root->right = MakeBST(preorder , Insearch + 1 , preEnd);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        TreeNode* root = MakeBST(preorder , 0 , n - 1);
        return root;
    }
};