#include <iostream>
using namespace std;

// Một Node trong cây
class Node {
    // Chứa thông tin của Node đó
    int data;
    // Con trỏ đến Node cha
    Node* fatherNode;

    // Con trỏ đến các Node con
    // Đây là một danh sách liên kết (con trỏ đến con đầu tiên)
    // Thứ tự ưu tiên từ nhỏ đến lớn (con nhỏ được duyệt trước)
    Node* firstChild;
    Node* nextSibling;
public:
    Node() {
        this->data = NULL;
        this->fatherNode = NULL;
        this->firstChild = NULL;
        this->nextSibling = NULL;
    }
    Node(int data) {
        this->data = data;
        this->fatherNode = NULL;
        this->firstChild = NULL;
        this->nextSibling = NULL;
    }
    // Các hàm khởi tạo khác nếu cần thiết

    int numberOfChild(){
        int numOfChild = 0;
        Node* currentNode = this->firstChild;
        while (currentNode != NULL){
            numOfChild++;
            currentNode = currentNode->nextSibling;
        }
        return numOfChild;
    }

    bool isBinarySearchTreeNode() {
        if (numberOfChild() > 2) return false;
        if (numberOfChild() == 2) {
            if (firstChild->data > data || firstChild->nextSibling->data < data) return false;
        }
        return true;
    }

    bool isMaxHeapTreeNode() {
        if (firstChild == NULL) return true;
        Node* currentNode = firstChild;
        while (currentNode != NULL) {
            if (currentNode->data > data) return false;
            currentNode = currentNode->nextSibling;
        }
        return true;
    }
    friend class Tree;
};

// Lớp Cây
class Tree {
    // Chứa một Node gốc
    Node* root;
public:
    Tree() {
        this->root = NULL;
    }
    Tree(int data){
        this->root = new Node(data);
    }
    // Các hàm khởi tạo khác nếu cần thiết

    // Hàm thêm một Node vào cây
    // Hàm trả về false nếu Node cha không tồn tại trên cây
    // hoặc Node father đã có con là data
    bool insertNodeToAnotherNode(int father, int data) {
        Node* fatherNode = search(this->root, father);
        if (fatherNode == NULL) return false;
        Node* childNode = search(this->root, data);
        if (childNode->fatherNode == fatherNode) return false;
        Node* insertedNode = new Node(data);
        insertedNode->fatherNode = fatherNode;
        return true;
    };

    // Hàm xoá một Node trên cây
    // Nếu không phải Node lá xoá Node đó và toàn bộ các Node con của nó
    // Hàm trả về số lượng Node đã xoá
    // Nếu Node data không tồn tại trả về 0 (zero)
    int remove(int data) {
        Node* deletedNode = search(this->root, data);
        if (deletedNode == NULL) return 0;
        if (deletedNode->firstChild == NULL) {
            if (deletedNode->fatherNode->firstChild == deletedNode) {
                deletedNode->fatherNode->firstChild = deletedNode->nextSibling;
            } else {
                Node* currentNode = deletedNode->fatherNode->firstChild;
                while (currentNode->nextSibling != deletedNode) {
                    currentNode = currentNode->nextSibling;
                }
                currentNode->nextSibling = deletedNode->nextSibling;
            }
            delete deletedNode;
            return 1;
        }
        int numOfDeletedNodes = 0;
        Node* currentNode = deletedNode->firstChild;
        while (currentNode != NULL) {
            numOfDeletedNodes += remove(currentNode->data);
            currentNode = currentNode->nextSibling;
        }
        if (deletedNode->fatherNode->firstChild == deletedNode) {
            deletedNode->fatherNode->firstChild = deletedNode->nextSibling;
        } else {
            Node* currentNode = deletedNode->fatherNode->firstChild;
            while (currentNode->nextSibling != deletedNode) {
                currentNode = currentNode->nextSibling;
            }
            currentNode->nextSibling = deletedNode->nextSibling;
        }
        delete deletedNode;
        return numOfDeletedNodes + 1;
    };
    

    // Hàm in ra các Node theo thứ tự preorder
    void preorder(){
        Node* currentNode = this->root;
        cout << currentNode->data << endl;
        if (currentNode->firstChild == NULL) return;
        currentNode = currentNode->firstChild;
        while (currentNode != NULL){
            preorder(currentNode);
            currentNode = currentNode->nextSibling;
        }
    };

    // Hàm in ra các Node theo thứ tự postorder
    void postorder() {
        Node* currentNode = this->root;
        if (currentNode->firstChild == NULL) {
            cout << currentNode->data << endl;
            return;
        }
        currentNode = currentNode->firstChild;
        while (currentNode != NULL){
            postorder(currentNode);
            currentNode = currentNode->nextSibling;
        }
        cout << currentNode->data << endl;
    };

    // Hàm kiểm tra cây nhị phân
    bool isBinaryTree() {
        if (this->root == NULL) return true;
        Node* currentNode = this->root;
        while (currentNode != NULL) {
            if (currentNode->numberOfChild() > 2) return false;
            while (currentNode->firstChild != NULL) {
                currentNode = currentNode->firstChild;
                if (currentNode->numberOfChild() > 2) return false;
            }
            if (currentNode->nextSibling) {
                currentNode = currentNode->nextSibling;
                if (currentNode->numberOfChild() > 2) return false;
            }
            if (!(currentNode->firstChild)) {
                while (currentNode->nextSibling == NULL && currentNode != this->root) {
                    currentNode = currentNode->fatherNode;
                }
                currentNode = currentNode->nextSibling;
            }

        }
    };

    // Hàm kiểm tra cây tìm kiếm nhị phân
    bool isBinarySearchTree() {
        if (!root) return false;
        Node* currentNode = root;
        while (currentNode != NULL) {
            if (!(currentNode -> isBinarySearchTreeNode())) return false;
            while (currentNode -> firstChild) {
                currentNode = currentNode -> firstChild;
                if (!(currentNode -> isBinarySearchTreeNode())) return false;
            }
            if (currentNode->nextSibling) {
                currentNode = currentNode -> nextSibling;
                if (!(currentNode -> isBinarySearchTreeNode())) return false;
            }
            // if no child -> leaf node -> traverse up -> go to next
            if (!(currentNode->firstChild)){
                while (!(currentNode->nextSibling) && currentNode != root) {
                    currentNode = currentNode -> fatherNode;
                }
                currentNode = currentNode -> nextSibling;
            }
        }
        return true;
    };

    // Hàm kiểm tra cây max-heap
    bool isMaxHeapTree() {
        if (root == NULL) return true;
        Node* currentNode = root;
        while (currentNode) {
            while (currentNode -> firstChild) {
                currentNode = currentNode -> firstChild;
                if (!(currentNode->isMaxHeapTreeNode())) return false;
            }
            if (currentNode -> nextSibling) {
                currentNode = currentNode -> nextSibling;
                if (!(currentNode->isMaxHeapTreeNode())) return false;
            }
            if (!(currentNode->firstChild)){
                while (!(currentNode->nextSibling) && currentNode != root) {
                    currentNode = currentNode -> fatherNode;
                }
                currentNode = currentNode -> nextSibling;
            }

        }

        return true;
    };

    // Hàm in ra các Node theo thứ tự inorder nếu là cây nhị phân
    void inorder() {
        Node* currentNode = this->root;
        if (currentNode->firstChild == NULL) {
            cout << currentNode->data << endl;
            return;
        }
        inorder(currentNode->firstChild);
        cout << currentNode->data << endl;
        currentNode = currentNode->firstChild->nextSibling;
        while (currentNode != NULL){
            inorder(currentNode);
            currentNode = currentNode->nextSibling;
        }
    };

    // Hàm trả về độ cao của cây
    int height(){
        if (this->root == NULL) return 0;
        Node* currentNode = this->root;
        int height = 0;
        while (currentNode != NULL) {
            height++;
            while (currentNode->firstChild != NULL) {
                currentNode = currentNode->firstChild;
                height++;
            }
            if (currentNode->nextSibling) {
                currentNode = currentNode->nextSibling;
                height++;
            }
            if (!(currentNode->firstChild)) {
                while (currentNode->nextSibling == NULL && currentNode != this->root) {
                    currentNode = currentNode->fatherNode;
                    height--;
                }
                currentNode = currentNode->nextSibling;
                height--;
            }
        }
        return height;
    };

    // Hàm trả về độ sâu của một Node
    int depth(int data){
        Node* currentNode = search(this->root, data);
        if (currentNode == NULL) return -1;
        int depth = 0;
        while (currentNode != NULL) {
            depth++;
            currentNode = currentNode->fatherNode;
        }
        return depth;
    };

    // Hàm đếm số lượng lá
    int numOfLeaves(){
        if (this->root == NULL) return 0;
        Node* currentNode = this->root;
        int numOfLeaves = 0;
        while (currentNode != NULL) {
            while (currentNode->firstChild != NULL) {
                currentNode = currentNode->firstChild;
            }
            if (currentNode->nextSibling) {
                currentNode = currentNode->nextSibling;
            }
            if (!(currentNode->firstChild)) {
                numOfLeaves++;
                while (currentNode->nextSibling == NULL && currentNode != this->root) {
                    currentNode = currentNode->fatherNode;
                }
                currentNode = currentNode->nextSibling;
            }
        }
        return numOfLeaves;
    };

    // Hàm trả về Node có giá trị lớn nhất
    int findMax(){
        if (this->root == NULL) return 0;
        Node* currentNode = this->root;
        int max = currentNode->data;
        while (currentNode != NULL) {
            if (currentNode->data > max) max = currentNode->data;
            while (currentNode->firstChild != NULL) {
                currentNode = currentNode->firstChild;
                if (currentNode->data > max) max = currentNode->data;
            }
            if (currentNode->nextSibling) {
                currentNode = currentNode->nextSibling;
                if (currentNode->data > max) max = currentNode->data;
            }
            if (!(currentNode->firstChild)) {
                while (currentNode->nextSibling == NULL && currentNode != this->root) {
                    currentNode = currentNode->fatherNode;
                }
                currentNode = currentNode->nextSibling;
            }
        }
        return max;
    };

    // Hàm trả về Node có nhiều con nhất
    int findMaxChild(){
        if (this->root == NULL) return 0;
        Node* currentNode = this->root;
        int max = currentNode->numberOfChild();
        while (currentNode != NULL) {
            if (currentNode->numberOfChild() > max) max = currentNode->numberOfChild();
            while (currentNode->firstChild != NULL) {
                currentNode = currentNode->firstChild;
                if (currentNode->numberOfChild() > max) max = currentNode->numberOfChild();
            }
            if (currentNode->nextSibling) {
                currentNode = currentNode->nextSibling;
                if (currentNode->numberOfChild() > max) max = currentNode->numberOfChild();
            }
            if (!(currentNode->firstChild)) {
                while (currentNode->nextSibling == NULL && currentNode != this->root) {
                    currentNode = currentNode->fatherNode;
                }
                currentNode = currentNode->nextSibling;
            }
        }
        return max;
    };

    // Hàm tìm Node có giá trị data
    Node* search(Node* root, int data) {
        if (root == NULL) return NULL;
        if (root->data == data) return root;
        Node* searchedNode = search(root->firstChild, data);
        if (searchedNode != NULL) return searchedNode;
        searchedNode = search(root->nextSibling, data);
        if (searchedNode != NULL) return searchedNode;
        return NULL;
    };
};

int main(int argc, char const *argv[]) {
    // Tạo ra một cây ngẫu nhiên có tối thiểu 30 Node
    Tree* tree = new Tree();
    for (int i = 0; i < 30; i++){
        tree->insertNodeToAnotherNode(i, i + 1);
    }

    // Test thử các hàm của lớp cây
    cout << "Preorder: " << endl;
    tree->preorder();
    cout << "Postorder: " << endl;
    tree->postorder();
    cout << "Inorder: " << endl;
    tree->inorder();
    cout << "Height: " << tree->height() << endl;
    cout << "Depth of 10: " << tree->depth(10) << endl;
    cout << "Number of leaves: " << tree->numOfLeaves() << endl;
    cout << "Max: " << tree->findMax() << endl;
    cout << "Max child: " << tree->findMaxChild() << endl;

    // Tạo ra một cây thoả mãn tính chất là Binary Search Tree và test lại
    Tree* binarySearchTree = new Tree();
    binarySearchTree->insertNodeToAnotherNode(9, 5);
    binarySearchTree->insertNodeToAnotherNode(9, 10);
    binarySearchTree->insertNodeToAnotherNode(5, 3);
    binarySearchTree->insertNodeToAnotherNode(5, 7);
    binarySearchTree->insertNodeToAnotherNode(10, 12);
    binarySearchTree->insertNodeToAnotherNode(10, 15);
    binarySearchTree->insertNodeToAnotherNode(3, 1);
    binarySearchTree->insertNodeToAnotherNode(3, 4);
    cout << binarySearchTree->isBinarySearchTree() << endl;

    // Tạo ra một cây thoả mãn tính chất là Max Heap Tree và test lại
    Tree* maxHeapTree = new Tree();
    maxHeapTree->insertNodeToAnotherNode(9, 5);
    maxHeapTree->insertNodeToAnotherNode(9, 6);
    maxHeapTree->insertNodeToAnotherNode(5, 3);
    maxHeapTree->insertNodeToAnotherNode(5, 7);
    maxHeapTree->insertNodeToAnotherNode(6, 4);
    maxHeapTree->insertNodeToAnotherNode(6, 8);
    maxHeapTree->insertNodeToAnotherNode(3, 1);
    maxHeapTree->insertNodeToAnotherNode(3, 2);
    cout << maxHeapTree->isMaxHeapTree() << endl;
    
    return 0;
}