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
