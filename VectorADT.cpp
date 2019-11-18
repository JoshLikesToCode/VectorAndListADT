#include "VectorADT.h"
#include <iostream>

VectorADT::VectorADT() {
    capacity = 10;
    size = 0;
    Array = new double[capacity];
    
    for (int i{0}; i < capacity; ++i)
        Array[i] = 0.0;
}

VectorADT::~VectorADT() {
    delete[] Array;
    Array = nullptr;
}

VectorADT::VectorADT( const VectorADT& c) {
    capacity = c.capacity;
    size = c.size;
    Array = new double[capacity];
    
    for (int i{0}; i < capacity; i++)
        Array[i] = c.Array[i];
}

std::ostream &operator<<(std::ostream &os, VectorADT &Vec) {
        for (int i{0}; i < Vec.get_size(); i++) {
            os << Vec[i];
            if ( i < Vec.get_size() -1)
                os << ", ";
        }
        return os;
}

int VectorADT::get_size() const {
    return size;
}

int VectorADT::length() const {
    return size;
}

int VectorADT::curr_capacity() const {
    return capacity;
}


void VectorADT::display() const {
    std::cout << "\nElements are: " << std::endl;
    for (int i{0}; i < capacity; i++)
        std::cout << Array[i] << " ";
    std::cout << std::endl;
}

void VectorADT::push_back(double val) {
    if (size > capacity)
        this -> resize(size + 1);
        
    Array[size] = val;
    size++;
}


void VectorADT::resize(int newSize) {
    if (newSize < this -> length() ) {
        size = newSize;
        return;
    } else if (newSize > this -> curr_capacity()) {
        double* temp = new double[ (2*newSize) ];
        for (int i{0}; i < (2*newSize); i++)
            temp[i] = 0.0;
        Array = temp;
    } else {
        size = newSize;
    }
}

void VectorADT::pop_back() {
    size--;
}

bool VectorADT::check_bounds(int index) {
    if (index >= 0 && index < size) 
        return true;
    return false;
}

double VectorADT::operator[](int index) {
    if (check_bounds(index))
        return Array[index];
    else
        return -1.0;
}

VectorADT VectorADT::operator=(VectorADT& rhs) {
    VectorADT v3;
    
    for (int i{0}; i < rhs.capacity; ++i)
        v3.push_back(rhs[i]);
        
    return v3;
}

VectorADT VectorADT::operator+( const VectorADT& v2) const {
    VectorADT v3;
    
    if ( size == v2.get_size()) {
        for (int i{0}; i < get_size(); ++i)
            v3.push_back( (Array[i]) + v2.Array[i]);
    }
    return v3;
}