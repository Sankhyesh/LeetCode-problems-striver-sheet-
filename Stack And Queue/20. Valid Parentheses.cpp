class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        // cout<<s.size();
        for(auto i : s){
            if(i == '[' || i == '(' || i == '{'  ){
                st.push(i);
            }else{
                if(st.empty()) return false;
                // int c = st.top();
                
                
                if((i == ']' && st.top() == '[') || (i == ')' && st.top() == '(') || (i == '}' && st.top() == '{')){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        
        
        if(st.empty()){
            return true;
        }else{
            return false;
        }
        
    }
};

