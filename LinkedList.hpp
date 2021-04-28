#include "Node.hpp"

class LinkedList
{
    private: 
        Node* head;
        Node* tail;
        int count;
        void swap(int index1, int index2);
    
    public:
        LinkedList();
        void addEnd(int c);
        void display();
        int getCount();
        void insertionSortOnDefense();
        void mergeSort(LinkedList* list, int begin, int end);
        void merge(LinkedList* list, int begin1, int end1, int begin2, int end2);
        Node* get(int index);
        void removeFront();

};