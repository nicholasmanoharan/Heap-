#include <iostream> 
#include <cmath> 
#include "MaxHeap.h"
#define MAX_SIZE 100; 

MaxHeap::MaxHeap() : size(0) {} 

void MaxHeap::heapifyUp(int index) { 
    if (index <= 1) return; 
    int parent = index / 2;
    if (heap[index] > heap[parent]) { 
        std::swap(heap[index], heap[parent]); 
        heapifyUp(parent); 
    }
}

void MaxHeap::heapifyDown(int index) { 
    int leftChild = index * 2; 
    int rightChild = index * 2 + 1; 
    int largest = index; 

    if (leftChild <= size && heap[leftChild] > heap[largest]) { 
        largest = leftChild;
    }

    if (rightChild <= size && heap[rightChild] > heap[largest]) { 
        largest = rightChild; 
    }

    if (largest != index) { 
        std::swap(heap[index], heap[largest]); 
        heapifyDown(largest); 
    }
}

void MaxHeap::insert (int value) { 
    if (size >= MAX_SIZE) { 
        std::cerr << "Heap is at capacity :) \n" << std::endl;
        return; 
    }

    heap[++size] = value; 
    heapifyUp(size);
}

int MaxHeap::remove() { 
    if (size <= 0) { 
        std::cerr << "Heap is completely empty :(\n";
        return -1;
    }
    
    int root = heap[1]; 
    heap[1] = heap[size=--];
    heapifyDown(1); 
    return root; 

}

void MaxHeap::removeAll() { 
    while (size > 0) { 
        std::cout << remove() << std::endl; 
    }
}

void MaxHeap::displau() { 
    int levels = log2(size) + 1; 
    int currLevelNodes = 1; 
    int currLevelCount = 0; 

    for (int i = 1; i <= size; i++) { 
        std::cout << heap[i] << " "; 
        currLevelCount++; 

        if (currLevelCount == currLevelNodes) {
            std::cout << std::endl; 
            currLEvelCount = 0; 
            currLevelNodes *= 2; 
         }
    }
}