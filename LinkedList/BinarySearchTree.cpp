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
                        return;
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
                        return;
                    }
                }
            }
        }
        else {
            root = tmp;
        }
    }
    void Delete(int value) {
        if (!this->IsEmpty()) {
            Node* deleteNode = DeleteHelper(value);
            if (deleteNode) {
                if (!deleteNode->leftChild && !deleteNode->rightChild) {
                    if (deleteNode->data < deleteNode->parent->data) {
                        deleteNode->parent->leftChild = NULL;
                    }
                    else {
                        deleteNode->parent->rightChild = NULL;
                    }
                }
                else if (!deleteNode->leftChild && deleteNode->rightChild) {
                    if (deleteNode->data < deleteNode->parent->data) {
                        deleteNode->parent->leftChild = deleteNode->rightChild;
                    }
                    else {
                        deleteNode->parent->rightChild = deleteNode->rightChild;
                    }
                }
                else if (deleteNode->leftChild && !deleteNode->rightChild) {
                    if (deleteNode->data < deleteNode->parent->data) {
                        deleteNode->parent->leftChild = deleteNode->leftChild;
                    }
                    else {
                        deleteNode->parent->rightChild = deleteNode->leftChild;
                    }
                }
                else {
                    //curr node has 2 children, find pred or succ and figure out how the swap is gonna work
                }
            }
        }
    }
    Node* DeleteHelper(int value) {
        if (!this->IsEmpty()) {
            Node* currNode = root;
            while (currNode) {
                if (currNode->data == value) {
                    return currNode;
                }
                else if (currNode->data > value) {
                    currNode = currNode->leftChild;
                }
                else {
                    currNode = currNode->rightChild;
                }
            }
        }
        return NULL;
    }
    Node* FindPred(Node* searchNode) {
        if (searchNode->leftChild) {
            Node* currNode = searchNode->leftChild;
            while (currNode->rightChild) {
                currNode = currNode->rightChild;
            }
            return currNode;
        }
        return NULL;
    }
    Node* FindSucc(Node* searchNode) {
        if (searchNode->rightChild) {
            Node* currNode = searchNode->rightChild;
            while (currNode->leftChild) {
                currNode = currNode->leftChild;
            }
            return currNode;
        }
        return NULL;
    }
    bool Search(int value) {
        if (!this->IsEmpty()) {
            Node* currNode = root;
            while (currNode) {
            if (currNode->data == value) {
                return true;
            }
            else if (currNode->data > value) {
                currNode = currNode->leftChild;
            }
            else {
                currNode = currNode->rightChild;
            }
        }
        return false;
        }
    }
    void Print() {
        if (!this->IsEmpty()) {
            Print(root);
            std::cout << "Print Complete!" << std::endl;
            std::cout << std::endl;
        } 
        else {
            std::cout << "The BST is empty!" << std::endl;
        }
    }
    void Print(Node* currNode) {
        std::cout << "CurrNode has value " << currNode->data << std::endl;
        if (currNode->leftChild) {
            std::cout << currNode->data << " has left child " << currNode->leftChild->data << std::endl;
            Print(currNode->leftChild);
        }
        if (currNode->rightChild) {
            std::cout << currNode->data << " has right child " << currNode->rightChild->data << std::endl;
            Print(currNode->rightChild);
        }
        return;
    }
};
int main() {
    BinarySearchTree* test = new BinarySearchTree();
    test->Print();
    test->Insert(1);
    //test->Print();
    test->Insert(2);
    test->Insert(6);
    //test->Print();
    test->Insert(3);
    test->Insert(4);
    test->Insert(7);
    test->Insert(14);
    test->Insert(11);
    test->Insert(12);
    //test->Print();
    /*std::cout << test->FindPred(test->DeleteHelper(6))->data << std::endl;
    std::cout << test->FindSucc(test->DeleteHelper(2))->data << std::endl;*/
    test->Delete(2);
    test->Delete(14);
    test->Print();
}