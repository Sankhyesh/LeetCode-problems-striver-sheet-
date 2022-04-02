/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    if(!root) return -1;
    int res = -1;
 	while(root){
        if(root->val <= X){
            res = root->val;
            root = root->right;
        }
        else{
			root = root->left;
        }
    }   
    return res;
}
