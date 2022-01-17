class Node {
public:
    int key;
    int data;
    Node* next;
    Node* prev;
    Node(int key, int data) {
        this->key = key;
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};
class LRUCache {
public:
    int capacity;
    int count;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> table;
    LRUCache(int capacity) {
        this->capacity = capacity;
        count = 0;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (table.count(key)) {
            Node* temp = table[key];
            int result = temp->data;
            delete_node(temp);
            //adding current node at the front
            add_node(temp);
            return result;
        }
        else {
            return -1;
        }
    }
    void add_node(Node * new_node) {
        Node* after_head = head->next;
        new_node->next = after_head;
        new_node->prev = head;
        head->next = new_node;
        after_head->prev = new_node;
    }
    void delete_node(Node*del_node) {
        Node* del_prev = del_node->prev;
        Node* del_next = del_node->next;
        del_prev->next = del_next;
        del_next->prev = del_prev;
    }
    void print() {
        Node* current = head->next;
        while (current->next) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;


    }
    void put(int key, int value) {
        if (!table.count(key)) {
            count++;
            if (count > capacity) {
                count--;
                Node* lru = tail->prev;
                //delete the lru element
                delete_node(lru);
                //delete the lru element
                table.erase(lru->key);
            }
            Node* new_node = new Node(key, value);
            table[key] = new_node;
            add_node(new_node);
        }
        else {
            table[key]->data = value;
            Node* move_node = table[key];
            delete_node(move_node);
            add_node(move_node);
        }
    }
};
