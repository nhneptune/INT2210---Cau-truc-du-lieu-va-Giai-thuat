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

int main()
{
    int numberOfOperations;
    cin >> numberOfOperations;
    Queue queue;
    for (int i = 0; i < numberOfOperations; i++)
    {
        string operation;
        cin >> operation;
        if (operation == "enqueue")
        {
            int data;
            cin >> data;
            queue.enqueue(data);
        }
        else if (operation == "dequeue")
        {
            queue.dequeue();
        }
    }
    queue.print();
    return 0;
}