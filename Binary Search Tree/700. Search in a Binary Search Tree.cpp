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
// class Solution {
// public:
//     TreeNode* searchBST(TreeNode* root, int i) {
//         TreeNode* res;
//         if(!root){
//             return res;
//         }
//         stack<TreeNode*> st; 
//         st.push(root);
        
//         while(!st.empty()){
//             TreeNode* node = st.top();
//             st.pop();
            
//             if(i == node->val){
//                 return node;
//             }
//             if(i<=node->val){
//                 if(node->left)
//                     st.push(node->left);
//             }else{
//                 if(node->right){
//                     st.push(node->right);
//                 }
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != NULL && root->val != val){
            root = val < root->val? root->left: root->right;
        }
        return root;
    }
};
