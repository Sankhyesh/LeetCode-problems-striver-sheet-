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
    //if root is null then return false bcz we dont have ans
    // in that line  so return false
    if(!root){
        return false;
    }

    // push that node to the ans
    ans.push_back(root->val);


    if(root->val == B){
        return true;
    }

    if(getPath(root->left, ans, B) || getPath(root->right, ans, B)){ // if till the end u can 
    // found the path then return the true
        return true;
    }

    // if the path is not in that branch then pop the 
    // element return false 
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
