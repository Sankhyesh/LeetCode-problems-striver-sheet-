class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> res;
        
        // Step  1: if ther is no element then directly return res
        if(intervals.size() == 0){
            return intervals;
        }
        
        //step sort all intervals
        sort(intervals.begin(), intervals.end());
        vector<int> temp = intervals[0];
        
        for(auto i: intervals){
            if(i[0] <= temp[1]){
                temp[1] = max( temp[1], i[1]);
            }else{
                res.push_back(temp);
                temp = i;
            }
        }
        
        res.push_back(temp);
        return res;
        
    }
};
