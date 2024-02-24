#include <iostream>
#include "MaxHeap.h"

int main() {
    MaxHeap heap;

    std::string input;
    std::cout << "Enter numbers (separated by spaces) or filename: ";
    std::getline(std::cin, input);
    std::ifstream file(input);
    if (file) {
        heap.loadFromFile(input);
    } else {
        std::istringstream iss(input);
        int num;
        while (iss >> num) {
            heap.insert(num);
        }
    }

    
    std::cout << "Heap:" << std::endl;
    heap.display();
    std::cout << "Removing elements:" << std::endl;
    while (heap.getSize() > 0) { 
        std::cout << "Removed: " << heap.remove() << std::endl;
    }
    
    return 0;
}
