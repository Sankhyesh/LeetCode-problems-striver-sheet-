class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s = nums.size();
        int lo = 0,mid = 0, high = s - 1;
        for(int i = 0; i < s; i++){
            switch(nums[mid]){
                    
                case 0:
                    swap( nums[lo++], nums[mid++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap( nums[mid], nums[high--]);
                    break;
            }
        }
    }
};
