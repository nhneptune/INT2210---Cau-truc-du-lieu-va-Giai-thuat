#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

class Stack{
    public:
        Node* top;

        Stack(){
            this->top = NULL;
        }

        void push(int data){
            Node* newNode = new Node(data);
            if (this->top == NULL){
                this->top = newNode;
                return;
            }
            newNode->next = this->top;
            this->top = newNode;
        }

        void pop(){
            Node* nodeToDelete = this->top;
            this->top = this->top->next;
            delete nodeToDelete;
        }
};

class Queue{
    Stack stack1;
    Stack stack2;

    Queue(){
        this->stack1 = Stack();
        this->stack2 = Stack();
    }

    void enqueue(int data){
        if (this->stack1.top == NULL){
            this->stack1.push(data);
            return;
        }
        // Move all elements from stack1 to stack2
        Node* currentNode = this->stack1.top;
        while(currentNode != NULL){
            this->stack2.push(currentNode->data);
            currentNode = currentNode->next;
        }
        // Push new element to stack1
        this->stack1.push(data);
        //Move all elements from stack2 back to stack1
        currentNode = this->stack2.top;
        while(currentNode != NULL){
            this->stack1.push(currentNode->data);
            currentNode = currentNode->next;
        }
        // Empty stack2
        this->stack2.top = NULL;
    }

    void dequeue(){
        this->stack1.pop();
    }
};