class Solution {
private:
    
    void pallindrone(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int mark[]){
        
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        
        for(int i = 0; i<nums.size(); i++){
            if(!mark[i]){
                ds.push_back(nums[i]);
                mark[i] = 1;
                pallindrone(ds, nums, ans, mark);
                mark[i] = 0;
                ds.pop_back();
            }
        }
    }
    public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int mark[nums.size()];
        for(int i = 0; i<nums.size(); i++){
            mark[i] = 0;
        }
        pallindrone(ds, nums, ans, mark);
        return ans;
    }
};
