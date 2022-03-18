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
// class Solution {
// public:
    
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         stack<TreeNode *> st;
//         TreeNode* node = root;
//         while(true){
//             if(node != NULL){
//                 st.push(node);
//                 node = node->left;
//             }else{ // if node is null
//                 if(st.empty() == true)
//                     break;
                
//                 node = st.top();
//                 st.pop();
//                 res.push_back(node->val); 
//                 node = node->right;
//             }
//         }
        
//         return res;
//     }
// };


// mmoriss inorder taversal 
class Solution {
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* curr = root;
        while(curr != NULL){
            // if left is null then push it bcz in 
            // inorder node, left, right
            if(curr->left == NULL){
                res.push_back(curr->val);
                curr = curr->right;
            }else{ // if there is left node then goto that left -- rightmost node
                TreeNode *prev = curr->left;
                while(prev->right && prev->right != curr){
                    //prev->right != curr if it is  already connected as 
                    // then stop the loop
                    prev = prev->right;
                }
                // now check where prev is ryt now 
                //either it is now on null or if the thread is connected to 
                // curr already then remove 
                if(prev->right == NULL){
                    //make thread
                    prev->right = curr;
                    curr = curr->left;
                }else{//if the thread is already connected
                    //then remove the thread first
                    // if there is already thread then break it first
                    prev->right = NULL;
                    // in inorder we first go for the
                    res.push_back(curr->val);   
                    curr = curr->right;
                }
            }
        }
        return res;
    }
};

// morris preorder
class Solution{
  vector<int> preorderTraversal(TreeNode* root){
      vector<int> res;
      TreeNode* curr = root;
      while(curr != NULL){
          if(curr->left != NULL){
              res.push_back(curr->val);
              curr=curr->right;
          }else{
              TreeNode* prev = curr;
              while(prev->right != NULL && prev->right != curr){
                  prev=prev->right;
              }
              
              if(prev->right == NULL){// connect the thread
                  res.push_back(curr->val);
                  prev->right = curr;
                  curr = curr->left;
              }else{
                  prev->right = NULL;
                  curr = curr->right;
              }
          }
      }
      return res;
  }  
};

















