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

// REcursive Function
// class Solution {
// public:
//     void preorder( TreeNode* root, vector<int> &res){
//         if(root != NULL){
//             res.push_back(root->val);
//             preorder(root->left, res);
//             preorder(root->right, res);
//         }
//     }
    
//     vector<int> preorderTraversal(TreeNode* root) { 
//         vector<int> res;
//         preorder(root, res);
//         return res;
//     }
// };

// iterative method
class Solution {
public:
    
    vector<int> preorderTraversal(TreeNode* root) { 
        vector<int> res;
        if(!root){
            return res;
        }
        stack<TreeNode *> st;
        st.push(root);
        TreeNode* node = root;
        while(!st.empty()){
            
            node = st.top();
            st.pop();
            res.push_back(node->val);
            
            if(node ->right){// push the right first because at 
                // the time of the pop left will come first LIFO
                // node = node ->right;
                st.push(node -> right);
            }
            
            if(node->left){
                // node = node->left;
                st.push(node->left);
            }
            
            
        }
        return res;
    }
};
