#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

class MaxHeap {

private:

    //Setting the size for the heap
    static const int MAX_SIZE = 100;
    int heap[MAX_SIZE];

    //Checking the size of the heap
    int heapSize;
    void heapifyUp(int index);
    void heapifyDown(int index);

public:

    //Initializing the heap
    MaxHeap();
    void insert(int value);
    int remove();
    void removeAll();
    void display();
    void loadFromFile(const std::string& fileName);

};

#endif
