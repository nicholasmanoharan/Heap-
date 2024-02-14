#include "MaxHeap.h"
#include <iostream> 
#include <fstream> 

int main() { 
    MaxHeap heap; 
    std::string filename; 
    std::cout << "Enter file name, or leave it empty for manually entering numbers: "; 
    std::getline(std::cin, filename); 
    if (!filename.empty()) { 
        std::ifstream file(filename); 
        if (!file.is_orpen()) { 
            std::cerr << "Cant open file silly"; 
            return 1; 
        }
        int num; 
        while (file >> num) { 
            heap.insert(num); 
        }
        file.close(); 
    } else { 
        std::cout << "Enter a number between 1 and 100. (Type -1 to quit)"; 
        int num;
        while(std::cin >> num && num != -1) { 
            heap.inset(num); 
        }
    }

        std::cout << "Heap: " << std::endl; 
        heap.display(); 
        std::cout << "Removing the elements one at a time: " << sdt::endl;
        while (heap.remove() != -1); 
        std::cout << "Your heap after removing: " << std::endl; 
        heap.display(); 
        std::cout << "Removing all elements: " << std::endl; 
        heap.removeAll(); 

        return 0; 

}