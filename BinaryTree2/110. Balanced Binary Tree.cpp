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
    int dfHeight(TreeNode* root){
        if(!root){
            return 0;
        }
        int lh = dfHeight(root->left);
        if(lh == -1)return -1;
        
        int rh = dfHeight(root->right);
        if(rh == -1)return -1;
        
        if(abs(lh-rh) > 1)return -1;
        
        return max(lh, rh) + 1; 
    }
    
    bool isBalanced(TreeNode* root) {
        return dfHeight(root) != -1;
    }
    
};
