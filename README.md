# Linklist_oop
* Practice for object-oriented programming concept 
* Inheritance
* Polymorphism
* Composition
* Encapsulation
* Abstraction

## header file

```cpp
#include <iostream>

#ifndef LINKLIST_OOP_H
#define LINKLIST_OOP_H

class Node
{
private:
    int data;
    Node *next = NULL;
public:
    Node(int);
    int getData();
    void setData(int);
    Node *getNext();
    void setNext(Node*);
};


class Linklist
{
private:
    Node *head;
    Node *tail;
public:
    Linklist();
    ~Linklist();
    void createNode(int);
    virtual void insertNode(int);
    void deleteNode(int);
    std::string toString();
    Node *getHead();
    void setHead(Node*);
    friend std::ostream &operator<<(std::ostream &, Linklist *list);
};

class Sorted : public Linklist
{
public:
    Sorted();
    void insertNode(int);
};


#endif
```

## Node class implements file
```cpp
#include <iostream>
#include "linklist_oop.h"

Node::Node(int data) : data(data) {}
int Node::getData() {return data;}
void Node::setData(int data) {this->data = data;}
Node *Node::getNext() {return next;}
void Node::setNext(Node *node) {next = node;}
```

## Linklist class implements file
```cpp
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



```

## Sort clas implements file
```cpp
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
```

## main
```cpp
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
```