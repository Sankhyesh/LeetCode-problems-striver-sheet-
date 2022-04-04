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

// class for the NodeValues;

// class NodeValue {
// public:
//     int maxNode, minNode, maxSize, maxSum;
    
//     NodeValue(int minNode, int maxNode, int maxSize, int maxSum) {
//         this->maxNode = maxNode;
//         this->minNode = minNode;
//         this->maxSize = maxSize;
//         this->maxSum = maxSum;
//     }
// };

// class Solution {
// private:
//      NodeValue largestBSTSubtreeHelper(TreeNode* root) {
//         // An empty tree is a BST of size 0.
//         if (!root) {
//             return NodeValue(INT_MAX, INT_MIN, 0, 0);
//         }
        
//         // Get values from left and right subtree of current tree.
//         auto left = largestBSTSubtreeHelper(root->left);
//         auto right = largestBSTSubtreeHelper(root->right);
        
//         // Current node is greater than max in left AND smaller than min in right, it is a BST.
//         if (left.maxNode <= root->val && root->val <= right.minNode) {
//             // It is a BST.
//             return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), 
//                             left.maxSize + right.maxSize + 1, left.maxSum + right.maxSum + root->val);
//         }
        
//         // Otherwise, return [-inf, inf] so that parent can't be valid BST
//         return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize), max(left.maxSum, right.maxSum) );
//     }
// public:
//     int maxSumBST(TreeNode* root) {
//         int res = largestBSTSubtreeHelper(root).maxSum;
//         if(res>0){
//             return res;
//         }else{
//             return 0;
//         }
//     }
// };




struct T{ // structure for the creating the values basket 
    // siilar as the constructor
    bool isBst;
    int min;
    int max;
    int sum;
    T(): isBst(false){} // 
    T(bool isBst, int max, int min, int sum): isBst(isBst), max(max), min(min), sum(sum){} 
    // setting up the values of the constructor
    
};

class Solution{ 
    public:
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        traverse(root, ans);
        return ans;
    }
    
    private:
    T traverse(TreeNode* root, int &ans){
        if(!root){// if root is null return sum as the zero 
            // and set the max values as the most minimum 
            // and set the min values as the most maximum
            return T(true, INT_MIN, INT_MAX, 0);
        }
        
        T left = traverse(root->left, ans); // doing postorder 
        // goes till the complete left and then move 
        // to the right side 
        T right = traverse(root->right, ans); 
        
        if(!left.isBst || !right.isBst){ // any of the subtree is not bst then set then set the bst i
            return T(); // isBst to false;
        }
        if(root->val <= left.max || root->val >= right.min){
            return T();//if the bst condition is not possible then 
            // chnage the isBst to false;
        }
        
        //not is a valid BST 
        const int sum = root->val + left.sum + right.sum; //calculate the sum of the 
        // left subtree and right subtree 
        ans = max(ans, sum);
        //ans should be maximum of the current sum , and max
        
    // set the true to the T( ) and max as the root->val ,, and the max as the max(root->val, right.max) and min as root->min, left.min) 
        // sum      
         return T(true, max(root->val, right.max), min(root->val, left.min), sum);
        
        
    }
};
