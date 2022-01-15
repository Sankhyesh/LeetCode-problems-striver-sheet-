//optimal solution

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = nums[0];
        int slow = nums[0];
        
        do{//moving slow pointer by 1 and fast pointerby 2
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        // put the fast pointer at the 1st position
        fast = nums[0];
        
        // move the slow and fast pointer by 1
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};



// not a very optimal solution

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int duplicate = -1;
//         for(int i = 0; i<nums.size(); i++){
//                int cur = abs(nums[i]);
//             if(nums[cur] < 0){
//                 duplicate = cur;
//                 break;
//             }
            
//             nums[cur] *= -1;
//         }
        
//         //restore numbers
        
//         for(auto num: nums){
//             num = abs(num);
//         }
        
//         return duplicate;
//     }
// };
