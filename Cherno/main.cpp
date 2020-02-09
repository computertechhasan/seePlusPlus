#include <iostream>


void Pointers() {
    // Lets make a pointer
    int* imaptr;
    // It points to some random memory, and dereferencing it will lead to a segfault
    // std::cout << *imaptr << std::endl;
    
    // Lets make an int and point our pointer to it
    int x = 5;
    imaptr = &x;
    // The int's address and the ptr are the same 
    std::cout << "The int x is at " << &x << std::endl;
    std::cout << "imaptr is pointing to " << imaptr << std::endl;

    // void ptrs can point to anything
    void* imavoidptr;
    int y = 6;
    imavoidptr = &y;
    // will print y's address
    std::cout << imavoidptr << std::endl;
    double z = 5.2;
    imavoidptr = &z;
    // will print z's address
    std::cout << imavoidptr << std::endl;
}

void References() {
    // Lets make a reference
    int x = 5;
    int& imaref = x;
    // The int's address and the reference are the same 
    std::cout << "The int x is at " << &x << std::endl;
    std::cout << "imaref is pointing to " << &imaref << std::endl;
}

int main() {
    // Pointers();
    References();
}


