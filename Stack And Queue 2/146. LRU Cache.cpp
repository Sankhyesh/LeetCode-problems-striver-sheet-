class LRUCache {
    
public:
    class node{
        public:
        int key;
        int val;
        
        node *next;
        node *prev;
        
        node(int _key, int _val){
            key = _key;
            val = _val;
        }
    };
    
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    int cap;
    unordered_map<int, node*> m;
    
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(node * newnode){
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode; 
    }
    
    void deleteNode(node *delnode){
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        
        delprev->next = delnext;
        delnext->prev = delprev;
        
    }
    
    int get(int key_){
        if(m.find(key_) != m.end()){ // if we found the key in the map then
            // first we have to store the key val somewhere and then erase it form the 
            // map to update the lru address
            node* resnode  = m[key_];
            int res = resnode->val;
            m.erase(key_);
            
            //now delete it whereever it is in the linked list
            //and add again for the lru table format
            deleteNode(resnode);
            addNode(resnode);
            
            // update the latest address of the key which we used recently
            m[key_] = head->next;
            return res;
        }   
        return -1; // if key is not there then return null
    }
    
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){ // if there is any existing node already then we
            // have to update lru in table 
            node* existingnode = m[key];
            m.erase(key);
            deleteNode(existingnode);
        }        
        
        // if the capacity is full then we have to erase the least recently used 
        // element
        if(m.size() == cap){
            m.erase(tail->prev->key); // eraseing the last element value of the linked list 
            // from the hash map
            deleteNode(tail->prev);
        }
        addNode(new node(key, value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
