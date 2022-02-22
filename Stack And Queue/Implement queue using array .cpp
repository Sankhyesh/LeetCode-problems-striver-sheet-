class Queue {
    int *arr;
    int start, rear, maxSize;
public:
    Queue() {
        // Implement the Constructor
        maxSize = 100001;
        arr = new int[maxSize];
        start = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        
        if(start == rear){
            return true;
        }else{
            return false;
        }
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(rear == maxSize){
            cout<<"Q full";
        }else{
            arr[rear] = data;
            rear++;
            }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(rear == start){
            return -1;
        }else{
            int ans = arr[start];
            arr[start] = -1;
            start++;
            if(start == rear){
                start = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front() {
        // Implement the front() function
        if(start == rear){
            // empty 
            return -1;
        }else{
            return arr[start];
        }
    }
};
