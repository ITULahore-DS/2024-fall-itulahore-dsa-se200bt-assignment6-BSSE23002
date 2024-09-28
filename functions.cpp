//
// Created by Turab Hashmi on 9/27/2024.
//

#include "functions.h"

Node::Node(int data) {  // node constructor to initialise data/value
    this->data = data;
    next = nullptr;
}

void Node::setNext(Node *nextNode) {   // set next pointer
    this->next = nextNode;
}

Node *Node::getNext() {       // get the pointer
    return next;
}

void Node::setData(int value) {
    this->data = value;       //  set data in node
}

int Node::getData() {          // get data from node
    return data;
}

Stack::Stack() {        //initialize Queue attributes
    this->top = nullptr;
    count = 0;
}

bool Stack::isEmpty() {           // function to check empty stack
    if (top == nullptr) {
        return true;              // return true if empty
    } else {
        return false;             // return false if not empty
    }
}

void Stack::push(int data) {
    Node *newNode = new Node(data);    // make a new node

    newNode->setNext(top);      // point newNode to top
    top = newNode;              //set newNode as top
    count++;
}

int Stack::peek() {
    if (isEmpty()) {
        return -1;           // if empty stack return -1
    } else {
        return top->getData();   // get the data from top
    }
}

void Stack::pop() {
    if (isEmpty()) {
        return;
    } else {
        Node *newNode = top;      // store top in temporary pointer
        top = top->getNext();     // point top to the next node
        delete newNode;           // now delete the old top
        count--;
    }
}

int Stack::size() {
    return count;    // count will be the size of stack
}

void Stack::clear() {
    while (top != nullptr) {
        pop();      // clearing by using pop function
    }
}

void Stack::printStack() {
    Node *temp = top;         // store top in temporary pointer
    while (temp != nullptr) {
        cout << temp->getData() << "\t";     //traverse through  whole list
        temp = temp->getNext();          // sath sath update the pointer
        count--;
    }
}

Stack::~Stack() {
    clear();       // clear up alll memory by using clear function
}

Queue::Queue() {           //initialize Queue attributes
    front = nullptr;
    rear = nullptr;
    count = 0;
}

bool Queue::isEmpty() {      // function to check empty stack
    if (front == nullptr) {
        return true;         // return true if empty
    } else {
        return false;     // return false if not empty
    }
}

void Queue::enqueue(int data) {
    Node *newNode = new Node(data);

    if (front == nullptr) {    // if front is null that mean whole que is empty
        front = rear = newNode;    // so add new node and now front and rear will point the same node
    } else {

        rear->setNext(newNode);  // otherwise rear will point newNode
        rear = newNode;    // update the rear to new node
    }
    count++;
}

void Queue::dequeue() {
    if (isEmpty()) {
        return;         // is queue is already empty simply return
    } else {
        Node *currTop = front;       // store your front in temporary pointer
        front = front->getNext();     // update your front

        if (front == nullptr) {
            rear = nullptr;       // if front is null then back also be null
        }
        delete currTop;    //  delete the old front
        count--;
    }
}


int Queue::size() {
    return count;     // count will be the size of queue
}

void Queue::printQueue() {
    Node *temp = front;    //store iin a temporary pointer
    while (temp != nullptr) {
        cout << temp->getData() << "\t";    //traverse through whole queue and print
        temp = temp->getNext();    // sath sath update the temp pointer
    }
}

Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();   // clear memory by using dequeue function
    }
}

void menu() {
    Stack myStack;
    Queue myQueue;

    int choice;
    do {
        cout << "1. push in stack\n";
        cout << "2. pop from stack\n";
        cout << "3. peek of stack\n";
        cout << "4. printStack\n";
        cout << "5. enqueue\n";
        cout << "6. dequeue\n";
        cout << "7. printQueue\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1: {

                myStack.push(10);
                myStack.push(20);
                myStack.push(30);

                myStack.printStack();
                cout << "\n";
                cout << "\n";
                break;
            }
            case 2: {

                myStack.pop();
                cout << "Stack after  pop\n";
                myStack.printStack();
                cout << "\n";
                cout << "\n";
                break;
            }
            case 3: {

                cout << "Peek is: " << myStack.peek() << endl;
                myStack.pop();
                cout << "Peek after 1st pop: " << myStack.peek() << endl;
                myStack.pop();
                cout << "Peek after 2nd pop: " << myStack.peek() << endl;
                myStack.pop();
                cout << "Peek after 3rd pop: " << myStack.peek() << endl;
                myStack.pop();

                cout << "\n";
                break;
            }
            case 4: {
                myStack.push(10);
                myStack.push(20);
                myStack.push(30);
                myStack.push(40);
                myStack.push(50);
                myStack.printStack();
                cout << "\n";
                break;
            }
            case 5: {

                myQueue.enqueue(10);
                myQueue.enqueue(20);
                myQueue.enqueue(30);
                myQueue.printQueue();

                cout << "\n";
                break;
            }
            case 6: {

                myQueue.dequeue();
                myQueue.printQueue();

                cout << "\n";
                break;
            }
            case 7: {

                myQueue.printQueue();
                cout << "\n";
                break;
            }
            case 8: {
                cout << "Exiting the program." << endl;
                cout << "\n";
                break;
            }
            default: {
                cout << "Invalid choice, please try again." << endl;
                break;
            }
        }
    } while (choice != 8);
}


