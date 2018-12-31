#include <iostream>
struct Node {
    int data;
    Node *next;
    Node *prev;
    Node(int data) {
        next = NULL;
        prev = NULL;
        this->data = data;
    }
};
class LinkedList {
    private:
    Node *head, *tail;
    public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }
    void Insert(int value) {
        Node* tmp = new Node(value);
        if (!head) {
            head = tmp;
            tail = tmp;
        }
        else {
            tail->next = tmp;
            tmp->prev = tail;
            tmp->next = NULL;
            tail = tmp;
        }
    }
    void Delete(int value) {
        if (this->Search(value)) {
            Node* currNode = head;
            while (currNode) {
                if (currNode->data == value) {
                    if (currNode == head) {
                        head = currNode->next;
                        currNode = currNode->next;
                        continue;
                    }
                    if (currNode == tail) {
                        currNode->prev->next = NULL;
                        tail = currNode->prev;
                        currNode = currNode->next;
                        break;
                    }
                    currNode->prev->next = currNode->next;
                    currNode->next->prev = currNode->prev;
                }
                currNode = currNode->next;
            }
        }
    }
    bool Search(int value) {
        Node* currNode = head;
        while (currNode) {
            if (currNode->data == value) {
                return true;
            }
            currNode = currNode->next;
        }
        return false;
    }
    void Print() {
        if (!head) {
            std::cout << "The list is empty!" << std::endl;
        }
        else {
            Node* currNode = head;
            while(currNode) {
                std::cout << currNode->data << " -> ";
                currNode = currNode->next;
            }
            std::cout << std::endl;
        }
    }
};
int main() {
    LinkedList* myList = new LinkedList();
    myList->Print();
    myList->Insert(22);
    myList->Insert(44);
    myList->Insert(66);
    myList->Print();
    myList->Delete(44);
    myList->Print();
    myList->Delete(22);
    myList->Print();
    myList->Delete(66);
    myList->Print();
}