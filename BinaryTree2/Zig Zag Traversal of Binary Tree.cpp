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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> result;// vector for the rsult holding
        if(root == NULL){
            return result;
        }
        
        queue<TreeNode*> q; // queue to push the nodes partially
        q.push(root); 
        bool leftToright = true;
        
        while(!q.empty()){// until the queue is not empty
            int size = q.size();
            vector<int> row(size);
            for( int i = 0; i<size; i++){
                TreeNode* node = q.front();
                int index = leftToright ? i: (size-1-i);
                // row.push_back(index, node->val);
                row[index] = node->val;
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            leftToright = !leftToright;
            
            result.push_back(row);
        }
        return result;
        
    }
};
