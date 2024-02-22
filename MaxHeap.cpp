#include "MaxHeap.h"

MaxHeap::MaxHeap() : heapSize(0) {}

void MaxHeap::heapifyUp(int index) {
    if (index <= 1) return; // Root has been reached
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

    if (leftChild <= heapSize && heap[leftChild] > heap[largest])
        largest = leftChild;
    if (rightChild <= heapSize && heap[rightChild] > heap[largest])
        largest = rightChild;

    if (largest != index) {
        std::swap(heap[index], heap[largest]);
        heapifyDown(largest);
    }
}

void MaxHeap::insert(int value) {
    if (heapSize >= MAX_SIZE) {
        std::cerr << "Heap is full!" << std::endl;
        return;
    }
    heap[++heapSize] = value;
    heapifyUp(heapSize);
}

int MaxHeap::remove() {
    if (heapSize <= 0) {
        std::cerr << "Heap is empty!" << std::endl;
        return -1;
    }
    int root = heap[1];
    heap[1] = heap[heapSize--];
    heapifyDown(1);
    return root;
}

int MaxHeap::removeAll() {
    int removedCount = 0;
    while (heapSize > 0) {
        std::cout << remove() << std::endl;
        removedCount++;
    }
    return removedCount;
}

void MaxHeap::display() {
    int levels = log2(heapSize) + 1;
    int currLevelNodes = 1;
    int currLevelCount = 0;

    for (int i = 1; i <= heapSize; i++) {
        std::cout << heap[i] << " ";

        currLevelCount++;
        if (currLevelCount == currLevelNodes) {
            std::cout << std::endl;
            currLevelCount = 0;
            currLevelNodes *= 2;
        }
    }
}

// Definition of getSize() member function
int MaxHeap::getSize() const {
    return heapSize;
}
