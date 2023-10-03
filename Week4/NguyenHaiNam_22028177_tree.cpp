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
    }
    Node(int data) {
        this->data = data;
        this->fatherNode = NULL;
        this->firstChild = NULL;
    }
    // Các hàm khởi tạo khác nếu cần thiết

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
    bool insertNodeToAnotherNode(int father, int data) { };

    // Hàm xoá một Node trên cây
    // Nếu không phải Node lá xoá Node đó và toàn bộ các Node con của nó
    // Hàm trả về số lượng Node đã xoá
    // Nếu Node data không tồn tại trả về 0 (zero)
    int remove(int data);

    // Hàm in ra các Node theo thứ tự preorder
    void preorder();

    // Hàm in ra các Node theo thứ tự postorder
    void postorder();

    // Hàm kiểm tra cây nhị phân
    bool isBinaryTree();

    // Hàm kiểm tra cây tìm kiếm nhị phân
    bool isBinarySearchTree();

    // Hàm kiểm tra cây max-heap
    bool isMaxHeapTree();

    // Hàm in ra các Node theo thứ tự inorder nếu là cây nhị phân
    void inorder();

    // Hàm trả về độ cao của cây
    int height();

    // Hàm trả về độ sâu của một Node
    int depth(int data);

    // Hàm đếm số lượng lá
    int numOfLeaves();

    // Hàm trả về Node có giá trị lớn nhất
    int findMax();

    // Hàm trả về Node có nhiều con nhất
    int findMaxChild();

    // Hàm tìm Node có giá trị data
    Node* search(int data) {
        if (this->root == NULL) return NULL;
        else {
            Node* currentNode = this->root;
            while (currentNode != NULL) {
                if (currentNode->data == data) return currentNode;
                else if (currentNode->data > data) currentNode = currentNode->leftChild;
                else currentNode = currentNode->rightChild;
            }
            return NULL;
        }
    };
};

int main(int argc, char const *argv[]) {
    // Tạo ra một cây ngẫu nhiên có tối thiểu 30 Node
    // Test thử các hàm của lớp cây

    // Tạo ra một cây thoả mãn tính chất là Binary Search Tree và test lại
    
    // Tạo ra một cây thoả mãn tính chất là Max Heap Tree và test lại
    return 0;
}