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

class LinkedList{
    public:
        Node* head;
        Node* tail;

        LinkedList(){
            this->head = NULL;
            this->tail = NULL;
        }
        
        void insertNodeAtPosition(int data, int position){
            Node* insertedNode = new Node(data);
            if (position == 0){
                insertedNode->next = this->head;
                this->head = insertedNode;
                return;
            }
            Node* nodeBeforeinsertedNode = this->head;
            int index = 1;
            while (index < position){
                nodeBeforeinsertedNode = nodeBeforeinsertedNode->next;
                index++;
            }
            insertedNode->next = nodeBeforeinsertedNode->next;
            nodeBeforeinsertedNode->next = insertedNode;
        }

        void deleteNodeAtPosition(int position){
            if (position == 0){
                Node* nodeToDelete = this->head;
                this->head = this->head->next;
                delete nodeToDelete;
                return;
            }
            Node* nodeBeforeNodeToDelete = this->head;
            int index = 1;
            while (index < position){
                nodeBeforeNodeToDelete = nodeBeforeNodeToDelete->next;
                index++;
            }
            Node* nodeToDelete = nodeBeforeNodeToDelete->next;
            nodeBeforeNodeToDelete->next = nodeToDelete->next;
            delete nodeToDelete;
        }

        void printLinkedList(){
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
    LinkedList linkedList;
    int numberOfOperation;
    cin >> numberOfOperation;
    for (int i = 0; i < numberOfOperation; i++)
    {
        string operation;
        cin >> operation;
        if (operation == "insert"){
            int position, data;
            cin >> position >> data;
            linkedList.insertNodeAtPosition(data, position);
        }
        else if (operation == "delete"){
            int position;
            cin >> position;
            linkedList.deleteNodeAtPosition(position);
        }
    }
    linkedList.printLinkedList();
    return 0;
}