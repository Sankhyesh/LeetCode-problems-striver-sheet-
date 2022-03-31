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
    void flatten(TreeNode* root) {
        
        bool flag = true;
        TreeNode* prev = NULL;
        flattens(root, flag, prev);
    }
    
    void flattens(TreeNode* &root, bool &flag, TreeNode* &prev){
        if(flag){
            prev = NULL;
            flag = false; 
        }
        if(root == NULL){
            return ;
        }
        flattens(root->right, flag, prev);
        flattens(root->left, flag, prev);
        
        
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};
