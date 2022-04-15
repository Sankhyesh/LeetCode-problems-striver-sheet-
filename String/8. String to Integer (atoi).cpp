enum State {q0, q1, q2, qd};

class StateMachine{
    // store current state value.
    State currentState;
    int res, sign;
    
    // TRansition to state q1;
    
    void toStateQ1(char &ch){
        sign = (ch == '-') ? -1 : 1;
        currentState = q1;
    }
    
    //Transition to state q2;
    void toStateQ2(int digit){
        currentState = q2;
        appendDigit(digit);
    }
    
    // transition to state dead state qd/
    void toStateQd(){
        currentState = qd;
    }
    
    // Append digit to result, if out of the range return clamped value;
    void appendDigit(int &digit){
        
        if((res > INT_MAX / 10) || (res == INT_MAX / 10 && digit > INT_MAX % 10)){
            if(sign == 1){
                
                res =INT_MAX;
            }else{
                // if sign is -1, clamp it to the INT_MIN
                res = INT_MIN;
                sign = 1;
            }
            
            // when the 32 bit int range is exceed , a dead state is reached;
            toStateQd();
        }else{
            res = res * 10 + digit;
        }
    }
    
    public:
    
    StateMachine(){
        currentState = q0;
        res = 0;
        sign = 1;
    }
    
    void transition(char &ch){
        if(currentState == q0){
            /// beginning state og the string 
            if(ch == ' '){
                return;
            }else if(ch == '-' || ch == '+'){
                // current charachter is a sign 
                toStateQ1(ch);
            }else if(isdigit(ch)){
                toStateQ2(ch - '0');
            }else {
                toStateQd();
            }
        } else if(currentState == q1 || currentState == q2){
            
            // previous char was a sign or digit
            if(isdigit(ch)){
                // current state is a digit
                toStateQ2(ch - '0');
            }else{
                // if not digit
                toStateQd();
            }
        }
    }
    
    int getInteger(){
        return sign*res;
    }

    State getState(){
        return currentState;
    }
    
    
};


class Solution {
public:
    int myAtoi(string s) {
        StateMachine Q;
        
        for(int i = 0; i< s.size() && Q.getState() != qd; i++){
            Q.transition(s[i]);
            }
        return Q.getInteger();
    }
};
