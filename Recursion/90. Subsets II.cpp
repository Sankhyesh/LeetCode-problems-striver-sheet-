class Solution {
public:
    vector<vector<int>> res;
    
    void powerSet(int ind, vector<int> nums, vector<int> &ds, vector<vector<int>> &res){
        
        res.push_back(ds);
        
        for(int i = ind; i<nums.size(); i++){
            
            if(i != ind && nums[i] == nums[i-1]){
                continue;
            }
            
            ds.push_back(nums[i]);
            powerSet(i+1, nums, ds, res);
            ds.pop_back();
        }
        
    } 
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        powerSet(0, nums, ds, res);
        return res;
    }
};
