#include <iostream>

using namespace std;

class doublyLinkedListNode{
    public:
        int data;
        doublyLinkedListNode *next;
        doublyLinkedListNode *prev;

        doublyLinkedListNode(int data) {
            this->data = data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class doublyLinkedList{
    public:
        doublyLinkedListNode *head;
        doublyLinkedListNode *tail;

        doublyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        doublyLinkedList(int arr[], int length) {
            this->head = nullptr;
            this->tail = nullptr;
            for (int i = 0; i < length; i++) {
                this->insertNodeAtTail(arr[i]);
            }
        }

        void insertNodeAtTail(int data) {
            doublyLinkedListNode *newNode = new doublyLinkedListNode(data);
            if (this->head == nullptr) {
                this->head = newNode;
                this->tail = newNode;
                return;
            }
            this->tail->next = newNode;
            newNode->prev = this->tail;
            this->tail = newNode;
        }

        int count_triplets(){
            doublyLinkedListNode *checkNode = this->head->next;
            int count = 0;
            while (checkNode != this->tail){
                if (checkNode->data + checkNode->prev->data + checkNode->next->data == 0){
                    count++;
                }
                checkNode = checkNode->next;
            }
            return count;
        }
};

int main()
{
    int length;
    cin >> length;
    int arr[length];
    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
    }
    doublyLinkedList *list = new doublyLinkedList(arr, length);
    cout << list->count_triplets() << endl;
    return 0;
}