#include <iostream>
#include <string>
#include <stdlib.h>
#include "LinkedList.hpp"

using namespace std;

int main(int argc, char** argv)
{
    LinkedList* list = new LinkedList();
    list->addEnd(4);
    list->addEnd(2);
    list->addEnd(1);
    list->addEnd(6);
    list->addEnd(0);
    list->addEnd(3);

    list->display();
    cout << "*********************************" << endl;
    list->mergeSort(list, 0, list->getCount() - 1);
    list->display();


}