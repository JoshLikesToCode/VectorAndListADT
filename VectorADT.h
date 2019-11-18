
#ifndef _VECTORADT_H_
#define _VECTORADT_H_

#include <iostream>

class VectorADT {
private:
   double* Array;
   int size;
   int capacity;
   
public: 
    
   VectorADT();
   VectorADT(const VectorADT& c);
   void push_back(double val );
   void resize(int newSize);
   void pop_back();
   int length() const;
   int curr_capacity() const;
   ~VectorADT();
   
   // overloaded operators
   double operator[](int index);
   VectorADT operator=(VectorADT& rhs);
   VectorADT operator+( const VectorADT& rhs) const;

   // my own helper functions
    bool check_bounds(int index);
    void display() const;
    int get_size() const;
    
    friend std::ostream &operator<<(std::ostream &os, VectorADT &Vec);
};

#endif // _VECTORADT_H_