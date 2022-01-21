class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
          int row = arr.size();
            int col = arr[0].size();
            
            int low = 0;
            int high = (row*col) - 1;
            
            while(low<=high){
                int mid = (low + (high - low)/2);
                
                if(arr[mid/col][mid%col] == target){
                    return true;
                }
                
                if(arr[mid/col][mid%col] < target){
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }
            return false;
    }
};
