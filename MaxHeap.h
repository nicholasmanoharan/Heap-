#ifndef MAX_HEAP_H
#define MAX_HEAP_H

class MaxHeap {
   
    private: 
        
        int heap [MAX_SIZE]; 
        int size;
        void heapifyUp(int index); 
        void heapifyDown(int index);

    public: 
        
        MaxHeap(); 
        void insert(int value); 
        int remove(); 
        void removeAll(); 
        void display(); 

};

#endif