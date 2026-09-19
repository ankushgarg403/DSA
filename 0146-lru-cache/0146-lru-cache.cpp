class LRUCache {
private:
    class Node{
    public:
        int key,value;
        Node* prev;
        Node* next;

        Node(int key , int value){
            this -> key = key;
            this -> value = value;
            prev = nullptr;
            next = nullptr;
        }
    };
    
    int capacity;
    map<int,Node*> m;
    Node* head;
    Node* tail;

    void deletenode(Node* node){
        Node* prevnode = node -> prev;
        Node* afternode = node -> next;

        prevnode -> next = afternode;
        afternode -> prev = prevnode;
    }

    void insertathead(Node* node){
        Node* currafternode = head -> next;
        head->next = node;
        node -> prev = head;
        node -> next = currafternode;
        currafternode -> prev = node;
    }
public:

    LRUCache(int capacity) {
        this -> capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        Node* node = m[key];
        deletenode(node);
        insertathead(node);

        return node -> value;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            Node* node = m[key];
            node -> value = value;
            deletenode(node);
            insertathead(node);
        }
        else{
            if(m.size() == capacity){
                Node* node = tail->prev;
                m.erase(node -> key);
                deletenode(node);
            }
            Node* node = new Node(key,value);
            m[key] = node;
            insertathead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
