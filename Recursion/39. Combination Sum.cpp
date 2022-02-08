class Solution {
public:
    
    void combSum(int ind, int target, vector<int> &arr, vector<vector<int>> &res, vector<int> &ds){
        // base case 
        if(ind == arr.size()){
            if(target == 0){
                res.push_back(ds);
                return;
            }
            return;
        }
        
        //pick up the element
        if(arr[ind] <= target){
            ds.push_back(arr[ind]);
            combSum(ind, target - arr[ind], arr, res, ds);
            ds.pop_back();
        }
        
        combSum( ind+1, target, arr, res, ds);       
    }
    public:

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> res;
        vector<int> ds;
        combSum(0, target, candidates, res, ds);
        return res;
    }
};
