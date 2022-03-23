//             int diameter = max({lh+rh , rd , ld});
//             pair<int ,int> p;
//             p.first = height;
//             p.second = diameter;
//             return p;
//         }
//         int diameterOfBinaryTree(TreeNode* root) {
//             pair<int,int> p;
//             p =  DiameterwithHeight(root);
//             return p.second;
//     }
int calculated( TreeNode* root , int &d){
if(root == NULL) return 0;
int ld = calculated(root->left , d);
int rd = calculated(root->right , d);
d = max(d,ld+rd);
return max(ld,rd) + 1;
}
int diameterOfBinaryTree(TreeNode* root) {
int d = 0;
calculated(root , d);
return d;
}