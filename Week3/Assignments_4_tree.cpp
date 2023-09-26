#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* leftChild;
        Node* rightChild;

        Node(int data){
            this->data = data;
            leftChild = NULL;
            rightChild = NULL;
    }
};

class binarySearchTree{
    Node* root;

    binarySearchTree(){
        this->root = NULL;
    }

    void print(Node* root){
        if (root->leftChild){
            print(root->leftChild);
        }
        cout << root->data << endl;
        if (root->rightChild){
            print(root->rightChild);
        }
    }

    Node* search(Node* root, int key){
        Node* searchedNode = root;
        while (searchedNode != NULL && searchedNode->data != key){
            if (key < searchedNode->data){
                if (searchedNode->leftChild == NULL) return searchedNode;
                searchedNode = searchedNode->leftChild;
            }
            else{
                if (searchedNode->rightChild == NULL) return searchedNode;
                searchedNode = searchedNode->rightChild;
            }
        }
        return searchedNode;
    }

    void insert (Node* root, int data){
        Node* fatherOfInsertedNode = search(root, data);
        Node* insertedNode = new Node(data);
        if (fatherOfInsertedNode == NULL){
            this->root = insertedNode;
            return;
        }
        if (fatherOfInsertedNode->data == data) return;
        if (data < fatherOfInsertedNode->data){
            fatherOfInsertedNode->leftChild = insertedNode;
        }
        else{
            fatherOfInsertedNode->rightChild = insertedNode;
        }
    }
};