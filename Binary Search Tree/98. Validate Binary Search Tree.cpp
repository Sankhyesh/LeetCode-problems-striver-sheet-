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
//     bool isValidBST(TreeNode* root) {
//         int i = 0 ;
//         if(!root){
//             return false;
//         }
//         return check(root);
//     }
    
//     bool check(TreeNode* root){
//         if(!root){
//             return false;
//         }
//         if(root->left){
//             if(root->val <= root->left->val){
//             return false;
//             }
//         }
                
//         if(root->right){
//             if(root->val>=root->right->val){
//                 return false;
//             }
//         }
//         check(root->left);
//         check(root->right);
//         return true;
//     }
// };

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return check(root, LONG_MIN, LONG_MAX);
    }
    
    bool check(TreeNode* root, long min_val, long max_val){
        if(root == NULL){
            return true;// returning true at the end of the 
            // alll checking
        }
        if(root->val <= min_val || root->val >= max_val){
            return false;
        }
        else
            return check(root->left, min_val, root->val) && check(root->right, root->val, max_val);
   
    }
};








