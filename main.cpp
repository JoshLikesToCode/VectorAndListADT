#include "VectorADT.h"
#include "ListADT.h"
#include <iostream>

using namespace std;

int main() {
    
    ListADT list1;
    list1.push_back(1);
    list1.push_back(2);
    
    ListADT list2 = list1;
    list1.recursive_display(list1.head);
    cout << endl;
    list2.recursive_display(list2.head);
    
    ListADT list3;
    list3 = list1;
    cout << endl;
    list3.recursive_display(list3.head);
    
    VectorADT vector1;
    vector1.push_back(3.0);
    vector1.push_back(5.2);
    VectorADT vector2 = vector1;
    vector1.display();
    vector2.display();
    
    
    
    
    return 0;
}