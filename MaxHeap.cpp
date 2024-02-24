#include "MaxHeap.h"

MaxHeap::MaxHeap() : heapSize(0) {}

void MaxHeap::insert(int value) {
    if (heapSize < MAX_SIZE) {
        heap[++heapSize] = value;
        heapifyUp(heapSize);
    } else {
        std::cerr << "The heap is full" << std::endl;
    }
}

int MaxHeap::remove() {
    if (heapSize == 0) {
        std::cerr << "The heap is empty!!" << std::endl;
        return -1;
    }

    int root = heap[1];
    heap[1] = heap[heapSize--];
    heapifyDown(1);
    return root;
}

void MaxHeap::removeAll() {
    while (heapSize > 0) {
        std::cout << remove() << std::endl;
    }
}

void MaxHeap::display() {
    int levels = static_cast<int>(log2(heapSize)) + 1;
    int currLevelCount = 0;
    int level = 0;

    for (int i = 1; i <= heapSize; i++) {
        if (currLevelCount == 0) {
            std::cout << std::endl;
            currLevelCount = pow(2, level);
            level++;
        }
        std::cout << heap[i] << "\t";
        currLevelCount--;
    }
    std::cout << std::endl;
}

void MaxHeap::loadFromFile(const std::string& fileName) {
    std::ifstream file(fileName);
    if (file.is_open()) {
        int num;
        while (file >> num) {
            insert(num);
        }
        file.close();
    } else {
        std::cerr << "Unable to open the file: " << fileName << std::endl;
    }
}

void MaxHeap::heapifyUp(int index) {
    int parent = index / 2;
    while (index > 1 && heap[index] > heap[parent]) {
        std::swap(heap[index], heap[parent]);
        index = parent;
        parent = index / 2;
    }
}

void MaxHeap::heapifyDown(int index) {
    int leftChild = 2 * index;
    int rightChild = 2 * index + 1;
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
