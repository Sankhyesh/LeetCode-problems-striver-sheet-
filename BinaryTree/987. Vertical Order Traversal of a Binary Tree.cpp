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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // to store the result 
        map<int, map<int, multiset<int> > >nodes;
        
        
        queue<
            pair<TreeNode*, pair<int, int>>
            > todo;
        todo.push({root, {0,0}});
        
        while(!todo.empty()){
            auto p = todo.front();
            todo.pop();
            
            TreeNode* node = p.first; //TreeNode*
            
            //second is a pair<int, int>
            int x = p.second.first;// for vertical 
            int y = p.second.second; // for level 
            
            nodes[x][y].insert(node->val); // store the value at vertical , level 
            
            // if there is left then decrese the vertical bcz we are moving left side 
            // and we are moving down so increase the level
            // push into the queue
            if(node->left){
                todo.push({node->left, {x-1, y+1}});
            }
            
            //if there is right then increase the vertical bcz we are moving right side
            // and we are moving down so always increase the level
            // push into the queue
            if(node->right){
                todo.push({node->right, {x+1, y+1}});
            }
        }
        
        
        
        vector<vector<int>> ans;
        
        // nodes map<int, map<int, multiset<int> > >
        for(auto q: nodes){
            vector<int> col;
            for(auto p : q.second){ //p = q.second  = map<int, multiset<int>>
                // col.end()'' insert at position always at end
                col.insert(col.end(),  p.second.begin(), p.second.end());
                // we have to push every thing from multiset<int>
                //it contains the nodes which overlap in asccending order 
                // or single node also
                // q.second.begin() to q.second.end()
            }    
            ans.push_back(col);
        }
        return ans;
        
    }
};
