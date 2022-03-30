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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        
        maxSum(maxi, root);
        
        return maxi;
    }
    
    int maxSum(int &maxi, TreeNode* root){
        
        if(root == NULL){
            return 0;
        }
        
        int leftSum = max(0, maxSum(maxi, root->left));
        // 0 is added bcz if sum is negative then we need not to add that to the 
        // answer bcz it will only give negative  result
        
        int rightSum = max(0, maxSum(maxi, root->right));
        
        maxi = max(maxi, leftSum + rightSum + root->val);
        // at every node we are updating the maxi
        
        
        return max(leftSum, rightSum) + root->val;
    }
};
