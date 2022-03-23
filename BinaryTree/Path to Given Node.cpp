/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool getPath(TreeNode* root, vector<int> &ans, int B){
    //if root is null then return false bcz 
    if(!root){
        return false;
    }

    ans.push_back(root->val);


    if(root->val == B){
        return true;
    }
    if(getPath(root->left, ans, B) || getPath(root->right, ans, B)){
        return true;
    }

    ans.pop_back();

    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    if(A == NULL){
        return ans;
    }

    getPath(A, ans, B);
    return ans;
}
