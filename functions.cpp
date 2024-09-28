//
// Created by Turab Hashmi on 9/27/2024.
//

#include "functions.h"

Node::Node(int data) {
    this->data = data;
    next = nullptr;
}

void Node::setNext(Node *nextNode) {
    this->next = nextNode;
}

Node *Node::getNext() {
    return next;
}

void Node::setData(int value) {
    this->data = value;
}

int Node::getData() {
    return data;
}

Stack::Stack() {
    this->top = nullptr;
    count = 0;
}

bool Stack::isEmpty() {
    if (top == nullptr) {
        return true;
    } else {
        return false;
    }
}

void Stack::push(int data) {
    Node *newNode = new Node(data);
    newNode->next = top;
    top = newNode;
    count++;
}

int Stack::peek() {
    if (isEmpty()) {
        return -1;
    }
    return top->getData();
}

void Stack::pop() {
    if (isEmpty()) {
        return;
    } else {
        top = top->next;
        count--;
    }
}

int Stack::size() {
    return count;
}

void Stack::clear() {
    while (top != nullptr) {
        top = top->next;
        count--;
    }
}

void Stack::printStack() {
    while (!isEmpty()) {
        cout << top->getData() << "\t";
        top = top->next;
        count--;
    }
}

Stack::~Stack() {
    while (!isEmpty()) {
        Node *temp = top;
        top = top->next;
        delete temp;
    }
    count = 0;
}

Queue::Queue() {
    top = nullptr;
    count = 0;
}

bool Queue::isEmpty() {
    if (top == nullptr) {
        return true;
    } else {
        return false;
    }
}

void Queue::enqueue(int data) {
    Node *newNode = new Node(data);

    if (top == nullptr) {
        top = newNode;
    } else {
        Node *temp = top;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    count++;
}

void Queue::dequeue() {
    if (isEmpty()) {
        return;
    } else {
        int currData = top->getData();
        Node *currTop = top;
        top = top->next;
        delete currTop;
        count--;
    }
}


int Queue::size() {
    return count;
}

void Queue::printQueue() {
    Node *temp = top;
    while (temp != nullptr) {
        cout << temp->getData() << "\t";
        temp = temp->next;
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
                myStack.push(10);
                myStack.push(20);
                myStack.push(30);

                myStack.pop();
                cout << "Stack after  pop\n";
                myStack.printStack();
                cout << "\n";
                cout << "\n";
                break;
            }
            case 3: {
                myStack.push(10);
                myStack.push(20);
                myStack.push(30);

                cout << "Peek is: " << myStack.peek() << endl;
                myStack.pop();
                cout << "Peek after 1st pop: " << myStack.peek() << endl;
                myStack.pop();
                cout << "Peek after 2nd pop: " << myStack.peek() << endl;
                myStack.pop();
                cout << "Peek after 3rd pop: " << myStack.peek() << endl;

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

                myQueue.dequeue();
                myQueue.dequeue();

                cout << "\n";
                break;
            }
            case 7: {
                myQueue.enqueue(10);
                myQueue.enqueue(20);
                myQueue.enqueue(30);
                myQueue.enqueue(40);
                myQueue.enqueue(50);
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
