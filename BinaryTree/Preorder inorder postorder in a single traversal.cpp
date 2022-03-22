/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
#include<stack>
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
 vector<vector<int>> ans(3);
    if(!root) return ans;
    stack<pair<BinaryTreeNode<int>*,int>> s;
    s.push({root,1});
    
    while(!s.empty()){
        auto it = s.top();
        s.pop();
        // in
        if(it.second == 1){
            ans[1].push_back(it.first -> data);
            it.second++;
            s.push(it);
            
            if(it.first->left != NULL){
                s.push({it.first->left, 1});
            }
        }
        
        // preorder
        else if(it.second == 2){
            ans[0].push_back(it.first->data);
            it.second++;
            s.push(it);
            
            if(it.first->right != NULL){
                s.push({it.first->right, 1});
            }
        }
        //post
        else{
           ans[2].push_back(it.first->data); 
        }
    }  
    return ans;
}









