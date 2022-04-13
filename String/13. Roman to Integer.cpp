class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        int n = s.length();
        if(n == 0){
            return 0;
        }
        
        unordered_map<char, int> mp;
        
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        // put all the data in the map;
        
        // "MCMXCIV" 1994  M
        // M - 1000 mp[M] >= mp[C]] = true so Plus the res += 1000
        // C - 100 mp[C] >= mp[M]] = False so subtract the res -= 100
            // .
            // .   
        
        for(int i = 0; i<n-1; i++){
            if(mp[s[i]] >= mp[s[i+1]]){ // 
                res += mp[s[i]];
            }else{
                res -= mp[s[i]];
            }
        }
        
        res += mp[s[n-1]];
        return res;
        
        
    }
};
