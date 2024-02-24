#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#define MAX_SIZE 100

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

class MaxHeap {
private:
    int heap[MAX_SIZE];
    int heapSize;
    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    MaxHeap();
    void insert(int value);
    int remove();
    int removeAll();
    void display();
    int getSize() const;
    void loadFromFile(const std::string& filename);
};

#endif

