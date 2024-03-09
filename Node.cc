#include <iostream>
#include "linklist_oop.h"

Node::Node(int data) : data(data) {}
int Node::getData() {return data;}
void Node::setData(int data) {this->data = data;}
Node *Node::getNext() {return next;}
void Node::setNext(Node *node) {next = node;}