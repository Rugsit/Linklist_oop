#include <iostream>
#include "linklist_oop.h"
using namespace std;

int main()
{
    Linklist *list1 = new Linklist();
    Linklist *list2 = new Sorted();
    list1->createNode(0);
    list2->createNode(0);
    for(int i = 10; i > 0; i--)
    {
        list1->insertNode(i);
        list2->insertNode(i);
    }
    list1->printNode();
    list2->printNode();
    delete list1;
    delete list2;
    return 0;
}