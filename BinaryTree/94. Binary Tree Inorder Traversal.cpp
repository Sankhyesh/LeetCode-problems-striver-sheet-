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

/// Recursive solutions
// class Solution {
// public:
//     void inorder(TreeNode* root, vector<int> &res){
//         if(root != NULL){
//         inorder(root -> left, res);
//         res.push_back(root->val);
//         inorder(root -> right, res);
//         }
//     }
    
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         inorder(root, res);
//         return res;
//     }
// };


// iteratie solutions
class Solution {
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> st;
        TreeNode* node = root;
        while(true){
            if(node != NULL){
                st.push(node);
                node = node->left;
            }else{ // if node is null
                if(st.empty() == true)
                    break;
                
                node = st.top();
                st.pop();
                res.push_back(node->val); 
                node = node->right;
            }
        }
        
        return res;
    }
};









