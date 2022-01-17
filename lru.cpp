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
            Node* before_temp = temp->prev;
            Node* after_temp = temp->next;
            before_temp->next = after_temp;
            after_temp->prev = before_temp;
            int result = temp->data;
            //adding current used node at the front
            Node* after_head = head->next;
            head->next = temp;
            temp->prev = head;
            temp->next = after_head;
            after_head->prev = temp;
            return result;
        }
        else {
            return -1;
        }
    }
    void add_node(int key, int value) {
        Node* new_node = new Node(key, value);
        table[key] = new_node;
        Node* after_head = head->next;
        new_node->next = after_head;
        new_node->prev = head;
        head->next = new_node;
        after_head->prev = new_node;
    }
    void delete_node() {
        table.erase(tail->prev->key);
        Node* lru = tail->prev;
        lru->prev->next = tail;
        tail->prev = lru->prev;
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
            if (count <= capacity) {
                add_node(key, value);
            }
            else {
                //deleting the last least recent used node
                count--;
                delete_node();
                add_node(key, value);
            }
        }
        else {
            table[key]->data = value;
            Node* temp = table[key];
            Node* before_temp = temp->prev;
            Node* after_temp = temp->next;
            before_temp->next = after_temp;
            after_temp->prev = before_temp;
            Node* after_head = head->next;
            temp->next = after_head;
            temp->prev = head;
            head->next = temp;
            after_head->prev = temp;

        }
    }
};
