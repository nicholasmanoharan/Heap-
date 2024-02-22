#include <iostream>
#include "MaxHeap.h"

int main() {
    MaxHeap heap;


    heap.insert(10);
    heap.insert(20);
    heap.insert(15);
    heap.insert(30); 
    std::cout << "Heap:" << std::endl;
    heap.display();
    
    std::cout << "Removing elements:" << std::endl;
    while (heap.getSize() > 0) { 
        std::cout << "Removed: " << heap.remove() << std::endl;
    }
    
    return 0;
}
