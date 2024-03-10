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
    cout << list1 << endl;
    cout << list2 << endl;
    delete list1;
    delete list2;
    return 0;
}