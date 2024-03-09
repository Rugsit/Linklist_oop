#include <iostream>
#include "linklist_oop.h"
using namespace std;

Sorted::Sorted() : Linklist() {}


void Sorted::insertNode(int data)
{
    Node *newnode = new Node(data);
    Node *curr = NULL;
    Node *prev = NULL;
    if(getHead()->getData() > data)
    {
        newnode->setNext(getHead());
        setHead(newnode);
        return;
    }
    for(curr = getHead(); curr; curr = curr->getNext())
    {
        if(curr->getData() < data)
        {
            newnode->setNext(curr->getNext());
            curr->setNext(newnode);
            return;
        }
        prev = curr;
    }
}