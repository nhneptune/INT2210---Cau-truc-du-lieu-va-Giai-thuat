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

class Queue{
    public:
        Node* head;
        Node* tail;

        Queue(){
            this->head = NULL;
            this->tail = NULL;
        }

        void enqueue(int data){
            Node* newNode = new Node(data);
            if (this->head == NULL){
                this->head = newNode;
                this->tail = newNode;
                return;
            }
            this->tail->next = newNode;
            this->tail = newNode;
        }

        void dequeue(){
            Node* nodeToDelete = this->head;
            this->head = this->head->next;
            delete nodeToDelete;
        }

        int peek(){
            if (this->head == NULL){
                return -1;
            }
            return this->head->data;
        }

        void print(){
            Node* currentNode = this->head;
            while (currentNode != NULL){
                cout << currentNode->data << " ";
                currentNode = currentNode->next;
            }
            cout << endl;
        }
};

class Stack{
    Queue queue1;
    Queue queue2;

    Stack(){
        this->queue1 = Queue();
        this->queue2 = Queue();
    }

    void push(int data){
        if (this->queue1.head == NULL){
            this->queue1.enqueue(data);
            return;
        }
        // Move all elements from queue1 to queue2
        Node* currentNode = this->queue1.head;
        while (currentNode != NULL){
            this->queue2.enqueue(currentNode->data);
            currentNode = currentNode->next;
        }
        // Enqueue new element to queue1
        this->queue1.enqueue(data);
        // Move all elements from queue2 back to queue1
        currentNode = this->queue2.head;
        while(currentNode != NULL){
            this->queue1.enqueue(currentNode->data);
            currentNode = currentNode->next;
        }
        //Empty queue2
        this->queue2.head = NULL;
        this->queue2.tail = NULL;
    }

    void pop(){
        this->queue1.dequeue();
    }
};