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