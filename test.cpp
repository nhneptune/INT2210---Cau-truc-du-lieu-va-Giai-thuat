#include <iostream>

using namespace std;

class Node {
    int data;
    Node* fatherNode;
    Node* firstChild;
    Node* nextSibling;


int numberOfChild(){
        int numOfChild = 0;
        Node* currentNode = this->firstChild;
        while (currentNode != NULL){
            numOfChild++;
            currentNode = currentNode->nextSibling;
        }
        return numOfChild;
    }

    bool isBinaryTreeNode() {
        if (numberOfChild() > 2) return false;
        return true;
    }
};

int main()
{


    return 0;
}

