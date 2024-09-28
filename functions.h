//
// Created by Turab Hashmi on 9/27/2024.
//

#ifndef INC_2024_FALL_ITULAHORE_DSA_SE200BT_ASSIGNMENT6_BSSE23002_FUNCTIONS_H
#define INC_2024_FALL_ITULAHORE_DSA_SE200BT_ASSIGNMENT6_BSSE23002_FUNCTIONS_H

#include "iostream"

using namespace std;

class Node {
    int data;
    Node *next;
public:

    Node(int data);

    void setNext(Node *nextNode);

    Node *getNext();

    void setData(int value);

    int getData();
};

class Stack {
public:
    Node *top;
    int count;

    Stack();

    ~Stack();

    bool isEmpty();

    void push(int data);

    int peek();

    void pop();

    int size();

    void clear();

    void printStack();
};

class Queue {
public:
//    Node *top;
    Node* front;
    Node* rear;
    int count;

    Queue();

    bool isEmpty();

    void enqueue(int data);

    int size();

    void dequeue();

    void printQueue();

    int peek ();

    void clear();

    ~Queue();
};

void menu();


#endif //INC_2024_FALL_ITULAHORE_DSA_SE200BT_ASSIGNMENT6_BSSE23002_FUNCTIONS_H
