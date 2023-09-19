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

        int peek(){
            if (this->top == NULL){
                return -1;
            }
            return this->top->data;
        }

        void print(){
            Node* currentNode = this->top;
            while (currentNode != NULL){
                cout << currentNode->data << " ";
                currentNode = currentNode->next;
            }
            cout << endl;
        }

        void printReverse(){
            Stack stack;
            Node* currentNode = this->top;
            while (currentNode != NULL){
                stack.push(currentNode->data);
                currentNode = currentNode->next;
            }
            stack.print();
        }
};

int main()
{
    Stack stack;
    int numberOfOperations;
    cin >> numberOfOperations;
    for (int i = 0; i < numberOfOperations; i++){
        string operation;
        cin >> operation;
        if (operation == "push"){
            int data;
            cin >> data;
            stack.push(data);
        }
        else if (operation == "pop"){
            stack.pop();
        }
    }
    stack.printReverse();
    return 0;
}
