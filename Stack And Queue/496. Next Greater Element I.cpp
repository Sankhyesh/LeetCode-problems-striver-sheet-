class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        vector<int> res;
        stack<int> s;
        reverse(nums2.begin(), nums2.end());
        
        for(int i : nums2){
            while(!s.empty() && s.top() <= i){
                s.pop();
            }
            if(s.empty()){
                mp[i] = -1;
            }else{
                mp[i] = s.top();
            }
            s.push(i);
        }
        for(int i = 0; i<nums1.size(); i++){
            res.push_back(mp[nums1[i]]);
        }
        return res;
    }
};
