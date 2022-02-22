// class MyQueue {
    
// public:
//     stack<int> s1,s2;
//     MyQueue() {
        
//     }
    
//     void reverse(int size, stack<int> &s1, stack<int> &s2){
//         for(int i = 0; i<size; i++){
//             s2.push(s1.top());
//             s1.pop();
//         }
        
//     }
    
//     void push(int x) {
//         reverse(s1.size(), s1, s2);
//         s2.push(x);
//         reverse(s2.size(), s2, s1);
//     }
    
//     int pop() {
//         if(s1.size() == 0){
//             return -1;
//         }
//         int x = s1.top();
//         s1.pop();
//         return x;
//     }
    
//     int peek() {
//         if(s1.size() == 0){
//             return -1;
//         }
//         return s1.top();
//     }
    
//     bool empty() {
//         return s1.size() == 0;
//     }
// };

// amortized optimal solution 
class MyQueue {
    
public:
    stack<int> input, output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(output.empty() == false){
            int x = output.top();
            output.pop();
            return x;
        }else{
            while(input.empty() == false){
                output.push(input.top());
                input.pop();
            }
            int x = output.top();
            output.pop();
            return x;
        }
    }
    
    int peek() {
        if(output.empty() == false){
            return output.top();
        }else{
            while(input.empty() == false){
                output.push(input.top());
                input.pop();
            }
            return output.top();
        }
    }
    
    bool empty() {
        if(output.empty() == false){
            return output.size()==0;
        }else{
            while(input.empty() == false){
                output.push(input.top());
                input.pop();
            }
            return output.size()==0;
        }
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

// /**
//  * Your MyQueue object will be instantiated and called as such:
//  * MyQueue* obj = new MyQueue();
//  * obj->push(x);
//  * int param_2 = obj->pop();
//  * int param_3 = obj->peek();
//  * bool param_4 = obj->empty();
//  */
