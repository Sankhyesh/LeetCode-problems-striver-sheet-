class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num1 = -1;
        int num2 = -1;
        int c1 = 0;
        int c2 = 0;
        for(int i = 0; i< n;i++){
            int ele = nums[i];
            if(ele == num1){
                c1++;
            }else if(ele == num2){
                c2++;
            }else if(c1 == 0){
                num1 = ele;
                c1 = 1;
            }else if(c2 == 0){
                num2 = ele;
                c2 = 1;
            } else{
                c1--;
                c2--;
            }
        }
        c1 = 0;
        c2 = 0;
        for(int i = 0; i<n; i++){
            if(num1 == num2){
                c1++;
            }else{
                if(nums[i] == num1){
                c1++;   
            }
            if(nums[i] == num2){
                c2++;
            }
            }
        }
        vector<int> res;
        if(c1>(n/3)){
            res.push_back(num1);
        }
        if(c2>(n/3)){
            res.push_back(num2);
        }
        
        return res;
    }
};
