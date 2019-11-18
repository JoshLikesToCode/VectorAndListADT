#ifndef _LISTADT_H_
#define _LISTADT_H_

#include <iostream>

class ListADT
{
public:
    
    class Node {
        public:
        Node () { value = 0; next = nullptr; };
        Node (int val) { value = val; next = nullptr; };
        int value;
        Node *next;
    };
    
    Node *head;
    int size;
    
    ListADT();
    
    ~ListADT();
    
    ListADT(int s, Node* head); // size = 0, head = nullptr
    ListADT(const ListADT& c); // copy ctor
    ListADT& operator=(ListADT& rhs);
    int operator[](int index);  
    
    friend std::ostream &operator<<(std::ostream &os, ListADT& list);
    
    void push_back(int val);
    void push_front(int val);
    void pop_back();
    void pop_front();
    int length() const;
    
    // helper functions
    void recursive_display(Node *p);
    int count_nodes(Node *p);
    int del(Node *p, int index);
};

#endif // _LISTADT_H_
