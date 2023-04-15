#include <iostream>

class Node {
public:
    int data;
    int occurrences;
    Node* next;
  
    Node()
    {
        data = 0;
        occurrences = 1;
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->occurrences = 1;
        this->next = NULL;
    }
};
