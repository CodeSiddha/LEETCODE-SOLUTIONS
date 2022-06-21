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
    bool getPath(TreeNode* root , TreeNode* target , vector<TreeNode*>&t){
       if (!root)
        return false;

      t.push_back(root);


      if (root == target)
        return true;


      if (getPath(root -> left, target, t) ||
            getPath(root -> right, target, t))
            return true;

      t.pop_back();
      return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        vector<TreeNode*> t1;
        vector<TreeNode*> t2;
        bool f1 = false;
        bool f2 = false;
        getPath(root , p , t1);
        getPath(root , q , t2);
        int n = t1.size();
        int m = t2.size();
        int i = n - 1;
        int j = m - 1;
        reverse(t1.begin(), t1.end());
        reverse(t2.begin() , t2.end());
        while(i - 1 >= 0 && j - 1>= 0 && t1[i] == t2[j] && t1[i - 1] == t2[j - 1]){
            cout << t1[i]->val << " " << t2[j]->val << endl;
            i--;
            j--;
        }
        return t1[i];
    }
};