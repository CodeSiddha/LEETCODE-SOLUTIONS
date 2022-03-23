// int HeightOfTree(TreeNode* root){
//     if(root == NULL){
//         return 0;
//     }
//     return 1 + max(HeightOfTree(root->left) , HeightOfTree(root->right));
// }
// int diameterOfBinaryTree(TreeNode* root) {
//     if(root == NULL){
//         return 0;
//     }
//     int option1 = HeightOfTree(root->left) + HeightOfTree(root->right);
//     int option2 = diameterOfBinaryTree(root->left);
//     int option3 = diameterOfBinaryTree(root->right);
//     return max({option1 , option2 ,option3});
// }
//         pair<int,int> DiameterwithHeight(TreeNode* root){
//             if(root == NULL){
//                 pair<int, int> p;
//                 p.first = 0;
//                 p.second = 0;
//                return p;
//             }
//             pair<int,int> leftsubtree = DiameterwithHeight(root->left);
//             pair<int ,int> rightsubtree = DiameterwithHeight(root->right);
//             int lh = leftsubtree.first;
//             int ld = leftsubtree.second;
//             int rh = rightsubtree.first;
//             int rd = rightsubtree.second;
//             int height = 1 + max(lh , rh);
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