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
    bool isSymmetric(TreeNode* root) {
        bool res = check(root->left, root->right);
        return res;
    }
    
    bool check(TreeNode* left, TreeNode* right){
        
        // base case 
        if(left == NULL || right == NULL){
            return left == right ;
        }
        
        // check the vlaues of mirror
        if(left->val != right->val){
            return false;
        }a
        
        
        bool leftSide = check(left->left, right->right);
        bool rightSide = check(left->right, right->left);
        return leftSide && rightSide;
    }
};
