#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

class MaxHeap {

private:

    static const int MAX_SIZE = 100;
    int heap[MAX_SIZE];
    int heapSize;
    void heapifyUp(int index);
    void heapifyDown(int index);

public:

    MaxHeap();
    void insert(int value);
    int remove();
    void removeAll();
    void display();
    void loadFromFile(const std::string& fileName);

};

#endif 
