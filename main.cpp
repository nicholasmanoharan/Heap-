#include <iostream>
#include <fstream>
#include <sstream>
#include "MaxHeap.h"

int main() {
    MaxHeap heap;
    std::string input;

    do {
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
        heap.removeAll();
        std::cout << "Do you want to use a new set of numbers? (yes/no): ";
        std::getline(std::cin, input);

    } while (input == "yes");
        return 0;
    

    
}
