/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    if(!root){
        return;
    }
    
    //check the childs combinly greater then the root or not
    // if not change the root to satisfy the conditions 
    
    int child = 0;
    if(root->left){
        child+=root->left->data;
    }
    if(root->right){
        child+=root->right->data;
    }
    
    if(child>=root->data){
        root->data = child;
    }else{// if childs are small then simply change both the values to the 
        // root values  and coming back from the traversal we 
        // we can also change the values of the root
//         to  satisifies the condtion
        if(root->left){
            root->left->data = root->data;
        }else if(root->right){
            root->right->data = root->data;
        }
    }
    
 
    changeTree(root->left);
    changeTree(root->right);
 	
    // after the return of the tree 
    // tben change its value to the
    // both hte sums onlu 
    int t= 0;
    if(root->left){
        t+=root->left->data;
    }
    if(root->right){
        t+=root->right->data;
    }
    
    if(root->right || root->left){
        root->data=t;
    }
    
}  
