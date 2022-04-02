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
    int kthSmallest(TreeNode* root, int k) {
        // inorder and while kth element 
        if(!root){
            return -1;
        }
        stack<TreeNode*> st;
        TreeNode* node = root;
        int c = 0;
        while(true){
            if(node!= NULL){
                st.push(node);
                node=node->left;
            }else{
                if(st.empty() == true){
                    break;
                }
                node = st.top();
                c++;
                if(k == c){
                    return node->val;
                }
                st.pop();
                node = node->right;
            }
        }
        return -1;
    }
};
