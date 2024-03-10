#include <iostream>
#include "linklist_oop.h"
using namespace std;


Linklist::Linklist() : head(NULL) {}
Linklist::~Linklist()
{
    cout << endl;
    Node *prev = NULL;
    Node *temp;
    for(Node *iter = head; iter; iter = iter->getNext())
    {
        temp = prev;
        if (iter != head) 
        {
            cout << "Delete: " << iter->getData() << " " << endl;
            delete temp;
        }
        prev = iter;
        

    }
    delete prev;
}

void Linklist::createNode(int data) 
{
    head = new Node(data);
    tail = head;
}
void Linklist::insertNode(int data)
{
    Node *newnode = new Node(data);
    tail->setNext(newnode);
    tail = newnode;
}
void Linklist::deleteNode(int data)
{
    Node *curr = head;
    Node *prev = NULL;
    if(head->getData() == data) 
    {
        Node *temp = head;
        head = head->getNext();
        delete temp;
        return;
    }
    for(; curr; curr = curr->getNext())
    {
        if (curr->getData() == data)
        {
            prev->setNext(curr->getNext());
            delete curr;
            return;
        }
        prev = curr;
    }
}
string Linklist::toString()
{
    string s = "";
    for(Node *iter = head; iter; iter = iter->getNext())
    {
        s += to_string(iter->getData()) + " --> "; 
    }
    return s;
}
Node *Linklist::getHead() {return head;}
void Linklist::setHead(Node *newhead) {head = newhead;}

ostream &operator<<(ostream &output, Linklist *list)
{
    output << list->toString();
    return output;
}


