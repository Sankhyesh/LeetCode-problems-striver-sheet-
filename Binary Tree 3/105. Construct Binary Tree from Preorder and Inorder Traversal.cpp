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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> imap;
        for(int i =0; i<inorder.size(); i++){
            imap[inorder[i]] = i;
        }
        
        TreeNode* root = buildTree(0, preorder.size()-1, preorder, 
                    0, inorder.size() - 1, inorder, imap);
        return root;
    }
    
    TreeNode* buildTree(int preStart, int preEnd, vector<int> &preorder, int instart, int inEnd, vector<int> &inorder,
                       map<int, int> &imap){
        
        
        //base case 
        if(preStart > preEnd || instart > inEnd){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = imap[root->val];
        int numsLeft = inRoot - instart;
        
        root->left = buildTree(preStart+1, preStart+numsLeft, preorder ,instart, inRoot-1, inorder, imap );
        root->right = buildTree(preStart+numsLeft+1, preEnd, preorder,inRoot+1, inEnd, inorder, imap);
        
        return root;
    }
};
