/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//             if(root == NULL || root == p || root == q){
//                 return root;
//             }
        
//         TreeNode* left = lowestCommonAncestor(root->left, p, q);
//         TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        
//         if(left == NULL){
//             return right;
//         }
//         else if(right == NULL){
//             return left;
//         }
//         else{
//             return root;
//         }
        
    
//     }
// };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return NULL;
        
        int curr = root->val;
        
        if(curr < p->val && curr< q->val){//if both are on the right side 
            return lowestCommonAncestor(root->right, p, q);
        }
        if(curr > p->val && curr < q->val){// if both are on left side 
            return lowestCommonAncestor( root->left, p, q);
        }
        return root;
    }
};
