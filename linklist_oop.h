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
    void printNode();
    Node *getHead();
    void setHead(Node*);

};

class Sorted : public Linklist
{
public:
    Sorted();
    void insertNode(int);
};


#endif