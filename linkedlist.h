#include <iostream>
#include "node.h"

using namespace std;

class Linkedlist {
  Node *head;

public:
  Linkedlist() { head = NULL; }

  void insertNode(int);

  void printList();

  int sumList();

  void deleteNode(int);
};

void Linkedlist::deleteNode(int nodeOffset) {
  Node *temp1 = head, *temp2 = NULL;
  int ListLen = 0;

  if (head == NULL) {
    cout << "List empty." << endl;
    return;
  }

  while (temp1 != NULL) {
    temp1 = temp1->next;
    ListLen++;
  }


  if (ListLen < nodeOffset) {
    cout << "Index out of range" << endl;
    return;
  }

  temp1 = head;

  if (nodeOffset == 1) {

    head = head->next;
    delete temp1;
    return;
  }

  while (nodeOffset-- > 1) {

    temp2 = temp1;

    temp1 = temp1->next;
  }

  temp2->next = temp1->next;

  delete temp1;
}

void Linkedlist::insertNode(int data) {
  Node *newNode = new Node(data);

  if (head == NULL) {
    head = newNode;
    return;
  }

  Node *temp = head;
  while (temp->next != NULL) {
    if(temp->occurrences == newNode->occurrences){
      temp->occurrences++;
      newNode->occurrences++;
    } 
    temp = temp->next;
  }

  temp->next = newNode;
}

void Linkedlist::printList() {
  Node *temp = head;

  if (head == NULL) {
    cout << "List empty" << endl;
    return;
  }

  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

int Linkedlist::sumList() {
  Node *temp = head;

  int sum = 0;
  if (head == NULL) {
    cout << "List empty" << endl;
    return 0;
  }

  while (temp != NULL) {
    sum = sum + temp->data;
    temp = temp->next;
  }

  return sum;
}
