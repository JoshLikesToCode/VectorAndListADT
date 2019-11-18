#include "ListADT.h"

    ListADT::ListADT() : head(nullptr), size(0) {} 
    
    ListADT::ListADT(const ListADT& c) {
        head = new Node(c.head -> value);
        size = c.size;
        
        Node* loopthrough = c.head -> next;
        Node *q = head;
        
        while ( loopthrough != nullptr ) {
            q -> next = new Node(loopthrough -> value);
            loopthrough = loopthrough -> next;
            q = q -> next;
        }
    }

    
    void ListADT::push_back(int val) {
        Node* node = new Node(val);
        Node* loopthrough = head;
        
        if (head == nullptr) {
            head = node;
            size++;
        }
        else {
            while ( loopthrough -> next != nullptr ) {
                loopthrough = loopthrough -> next;
            }
            loopthrough -> next = node;
            size++;
        }
    }
    
    void ListADT::push_front(int val) {
        Node* node = new Node(val);
        node -> next = nullptr;
        
        if (head == nullptr) {
            head = node;
            size++;
        } else {
            node -> next = head;
            head = node;
            size++;
        }
    }
    
    void ListADT::recursive_display(Node *p) {
        if ( p != NULL ) {
            std::cout << p -> value << " ";
            recursive_display(p -> next);
        }
        std::cout << std::endl;
    }
    
    int ListADT::count_nodes(Node *p) {
        int count{0};
    
        while ( p != NULL ) {
            count++;
            p = p -> next;
        }
        return count;
}   

    int ListADT::del(Node *p, int index) {
            
        // tailing pointer
        Node *q = NULL;
        // used for deleting a value
        int del_val = -1;
        
        // if first node
        if (index == 1) {
            q = head;
            del_val = head -> value;
            head = head -> next;
            delete q;
            
            return del_val;
            
        } else {
            for (int i{0}; i < index - 1; i++) {
                q = p;
                p = p -> next;
            }
            q -> next = p -> next;
            del_val = p -> value;
            delete p;
            
            return del_val;
    }
}
    
    void ListADT::pop_back() {
        if (head == nullptr)
            std::cout << "Size is 0" << std::endl;
            
        Node* loopthrough = head;
        if (head != nullptr) {
            if (head -> next == nullptr) {
                delete head;
                head = nullptr;
                size--;
            } else {
                while (loopthrough -> next != nullptr)
                    loopthrough = loopthrough -> next;
                size--;
            }
        }
    }
    
    void ListADT::pop_front() {
        Node* front = head -> next;
        delete head;
        head = front;
        size -= 1;
    }
    
    int ListADT::length() const {
        return size;
    }
    
    ListADT::~ListADT() {
        Node *toDel = head;
         while (toDel) {
            head = head -> next;
            delete toDel;
            toDel = head;
         }
    } 
    
    
    int ListADT::operator[](int index) {
        if (index < count_nodes(head) ) {
            int counter{0};
            Node* loopthrough = head;
            while (counter < index) {
                loopthrough = loopthrough -> next;
                counter++;
            }
            return (loopthrough -> value);
        }
        std::cout << "You entered an index out of bounds." << std::endl;
        return -1;
    }
    
    std::ostream &operator<<(std::ostream &os, ListADT &list) {
        int index{0};
        while (index < list.size ) {
            os << list[index];
        if ( index < list.size -1 )
            os << ", ";
        index++;
        }
        os << ".";
        return os;
    }

    
    ListADT& ListADT::operator=(ListADT& rhs) {

        // 1) dellocate *this memeory space if any
        // 2) Traverse the rhs nodes, one by one.
        // 3) copy each node and add a new node to the end of list
        // 4) update the size
        // return lhs or rhs
        
        if (this -> size == 0) {
            Node *toDel = head;
                while (toDel) {
                    head = head -> next;
                    delete toDel;
                    toDel = head;
            }
        }
        
        if ( this != &rhs) {
            ListADT temp(rhs);
            std::swap(head, temp.head);
        }
        return *this;
    }
