#include "LinkedList.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

Node* LinkedList::get(int index)
{
    Node* currNode = head;
    for(int i = 0; i < index; i++)
    {
        currNode = currNode->getNextNode();
    } 
    return currNode;
}

void LinkedList::swap(int index1, int index2)
{
    int smaller = index1;
    int larger = index2; 
    Node* smallerNode = this->get(index1);
    Node* largerNode = this->get(index2);

    int temp = smallerNode->getPayload();
    smallerNode->setPayload(largerNode->getPayload());
    largerNode->setPayload(temp);
}


LinkedList::LinkedList()
{
    this->count = 0;
    this->head = NULL;
    this->tail = NULL;
}

void LinkedList::addEnd(int c)
{
    Node* n = new Node(c);
    if(this->count == 0)
    {
        this->head = n;
        this->tail = n;
    }
    else
    {
        n->setPrevNode(this->tail);
        this->tail->setNextNode(n);
        this->tail = n;
    }
    this->count++;
}

void LinkedList::display()
{
    Node* currNode = this->head;
    for(int i = 0; i < this->count; i++)
    {
        cout << currNode->getPayload() << endl;
        currNode = currNode->getNextNode();
    }
}

int LinkedList::getCount()
{
    return this->count;
}


void LinkedList::mergeSort(LinkedList* list, int begin, int end)
{
    if(begin != end)
    {
        int begin1 = begin;
        int end1 = (begin + end) / 2;
        int begin2 = end1 + 1;
        int end2 = end;
        mergeSort(list, begin1, end1);
        mergeSort(list, begin2, end2);

        merge(list, begin1, end1, begin2, end2);
    }
}

void LinkedList::merge(LinkedList* list, int begin1, int end1, int begin2, int end2)
{
    int size = end2 - begin1 + 1;
    LinkedList* temp = new LinkedList;
    int pos1 = begin1;
    int pos2 = begin2;

    for(int i = 0; i < size; i++)
    {
        if(pos1 <= end1 && pos2 <= end2)
        {
            if(list->get(pos1)->getPayload() < list->get(pos2)->getPayload())
            {
                temp->addEnd(list->get(pos1)->getPayload());
                pos1++;
            }
            else
            {
                temp->addEnd(list->get(pos2)->getPayload());
                pos2++;
            }
        }
        else if (pos1 <= end1)
        {
            temp->addEnd(list->get(pos1)->getPayload());
            pos1++;
        }
        else
        {
            temp->addEnd(list->get(pos2)->getPayload());
            pos2++;
        }
    }

    int tempPos = 0;
    for(int j = begin1; j <= end2; j++)
    {
        list->get(j)->setPayload(temp->get(tempPos)->getPayload());
        tempPos++;
    }

}

void LinkedList::removeFront()
{
    if(this->count > 0)
    {
        Node* front = this->head;
        int temp = front->getPayload();

        this->head = front->getNextNode();
        this->count--;

        if(this->head)
        {
            this->head->setPrevNode(NULL);
        }

        if(this->tail == front)
        {
            this->tail = NULL;
        }

        front->setNextNode(NULL);
        front->setPrevNode(NULL);
        delete(front);
    }
}

