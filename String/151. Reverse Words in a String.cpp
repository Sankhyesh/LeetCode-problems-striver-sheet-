
class Solution {
public:
    string reverseWords(string s) {
        
        vector<string> result;
        string res = "";
        
        stringstream ss(s);
        string word;
        while (ss >> word) {
            result.push_back(word);
        }
        
        int h = result.size() - 1;
        int l = 0;
        while(l<h){
            swap(result[h], result[l]);
            l++;
            h--;
            }

        h = result.size() - 1;
        
        for(int i = 0; i<=h; i++){
            res = res + result[i] + " ";
        }
        return res.substr(0, res.size() - 1);
        
    }
};
