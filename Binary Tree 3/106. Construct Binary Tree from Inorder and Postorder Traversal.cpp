/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) 
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> imap;
        for(int i =0; i<inorder.size(); i++){
            imap[inorder[i]] = i;
        }
        
        int postStart = 0;
        int postEnd = postorder.size() - 1;
        
        int inStart = 0;
        int inEnd = inorder.size()-1;
        
        TreeNode* root = build(postStart, postEnd, postorder, inStart, inEnd, inorder, imap);
        return root;
    }
    
    TreeNode* build(int postStart, int postEnd, vector<int> &postorder, int inStart, int inEnd, vector<int> &inorder, map<int, int> &imap){
        if(inStart > inEnd)return NULL;
        
        TreeNode* root = new TreeNode(postorder[postEnd]);// last node is the root node in 
        // post order so keep it in that way only
        
        int  inRoot = imap.at(postorder[postEnd]);
        // position of the root in map
        
        int leftSide = inRoot - inStart;
        // how many are in the left side of the inorder 
            
        root->left = build( postStart, postStart + leftSide - 1, postorder,
                           inStart, inRoot - 1, inorder, imap);
        // post every element for its left subtree are in left side of the array 
        
        
        root->right = build( postStart+leftSide, postEnd - 1, postorder, 
                            inRoot+1, inEnd, inorder, imap);
        /// in post order every element for its right subtree is from the right side of
        // of the left subarray in the post array upto the root position
        
        return root;
    }
};
