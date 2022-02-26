struct Node{
    int key, val, cnt;
    Node *next;
    Node *prev;
    
    Node(int _key, int _value){
        key = _key;
        val = _value;
        cnt = 1;
    }
};

struct List{
    int size;
    Node *head;
    Node *tail;
    
    List(){
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    void addFront(Node *node){
        Node *temp = head -> next;
        node->next = temp;
        node->prev= head;
        head->next = node;
        temp->prev = node;
        size++;
    }
    
    void removeNode(Node *delNode){
        Node* delprev = delNode->prev;
        Node* delnext = delNode->next;
        
        delprev->next = delnext;
        delnext->prev = delprev;
        
        size--;
    }
      
};

class LFUCache {
public:
    map<int , Node*> keyNode;
    map<int , List*> freqListMap;
    
    int maxSizeCache;
    int minFreq;
    int currSize;
    
    
    
    
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        currSize = 0;
    }
    
    
    void updateFreq(Node *node){
        
        keyNode.erase(node->key);
        
        freqListMap[node->cnt]->removeNode(node);
        
        if(node->cnt == minFreq && freqListMap[node->cnt] -> size == 0){
            minFreq++;
        }
        List *nextHigherFreqList = new List();
        
        if(freqListMap.find(node->cnt+1) != freqListMap.end()){
            nextHigherFreqList = freqListMap[node->cnt+1];
        }
        node ->cnt+=1;
        nextHigherFreqList->addFront(node); // add in front of the next higher freq list
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node; // updat=e the key node  map
        
        
    }
     
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            int val = node->val;
            updateFreq(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSizeCache == 0){
            return;
        }
        
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->val = value;
            updateFreq(node);
        }else{
            
            if(currSize == maxSizeCache){
                List *list = freqListMap[minFreq];
                keyNode.erase(list->tail -> prev -> key);
                freqListMap[minFreq] -> removeNode(list->tail->prev);
                currSize--;
            }
            // if we have to add new node then increase the curssize
            currSize++;
            
            minFreq = 1;
            List *listFreq = new List();
            
            //check if there is already existing a list with 1 freq 
            if(freqListMap.find(minFreq) != freqListMap.end()){
                listFreq  = freqListMap[minFreq];
            }
                // create a new node with the new values
                Node *node = new Node(key, value);
                listFreq->addFront(node);
                keyNode[key] = node;
                freqListMap[minFreq] = listFreq;
                
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
