// class Solution {
// private:
    
//     void pallindrone(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int mark[]){
        
//         if(ds.size() == nums.size()){
//             ans.push_back(ds);
//             return;
//         }
        
//         for(int i = 0; i<nums.size(); i++){
//             if(!mark[i]){
//                 ds.push_back(nums[i]);
//                 mark[i] = 1;
//                 pallindrone(ds, nums, ans, mark);
//                 mark[i] = 0;
//                 ds.pop_back();
//             }
//         }
//     }
//     public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> ans;
//         vector<int> ds;
//         int mark[nums.size()];
//         for(int i = 0; i<nums.size(); i++){
//             mark[i] = 0;
//         }
//         pallindrone(ds, nums, ans, mark);
//         return ans;
//     }
// };


/// with out taking extra space 

class Solution {
private:
    
    void pallindrone(int index, vector<int> &nums, vector<vector<int>> &ans){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i = index; i< nums.size(); i++){
            swap( nums[index], nums[i]);
            pallindrone(index + 1, nums, ans);
            swap(nums[index], nums[i]);
        }
        
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        pallindrone(0, nums, ans);
        return ans;
    }
};

















