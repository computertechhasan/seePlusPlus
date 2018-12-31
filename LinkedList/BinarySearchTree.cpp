#include <iostream>
struct Node {
    int data;
    Node *leftChild;
    Node *rightChild;
    Node *parent;
    Node(int data) {
        leftChild = NULL;
        rightChild = NULL;
        parent = NULL;
        this->data = data;
    }
};

class BinarySearchTree {
    private:
    Node *root;
    public:
    BinarySearchTree() {
        root = NULL;
    }
    bool IsEmpty() {
        if (!root) {
            return true;
        }
        return false;
    }
    void Insert(int value) {
        Node* tmp = new Node(value);
        if (!this->IsEmpty()) {
            Node *currNode = this->root;
            while (currNode) {
                if (currNode->data > tmp->data) {
                    if (currNode->leftChild) {
                        currNode = currNode->leftChild;
                        continue;
                    }
                    else {
                        currNode->leftChild = tmp;
                        tmp->parent = currNode;
                    }
                }
                else {
                    if (currNode->rightChild) {
                        currNode = currNode->rightChild;
                        continue;
                    }
                    else {
                        currNode->rightChild = tmp;
                        tmp->parent = currNode;
                    }
                }
            }
        }
        else {
            root = tmp;
        }
    }
    void Print() {
        if (!this->IsEmpty()) {
            Print(root);
        } 
        else {
            std::cout << "The BST is empty!" << std::endl;
        }
    }
    void Print(Node* currNode) {
        std::cout << currNode->data << std::endl;
        if (currNode->leftChild) {
            Print(currNode->leftChild);
            std::cout << "    ";
        }
        if (currNode->rightChild) {
            Print(currNode->rightChild);
        }
    }
};
int main() {
    BinarySearchTree* test = new BinarySearchTree();
    test->Print();
    test->Insert(1);
    test->Print();
    test->Insert(2);
    test->Insert(-1);
    test->Print();
}