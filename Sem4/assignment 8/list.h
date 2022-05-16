#ifndef LIST_
#define LIST_

#include <iostream>
#include "stack.h"
using namespace std;

class linkedList;

class Node {
    string data;

   public:
    Node* next;
    linkedList* ref;
    Node(string data, linkedList* ref);
    void insert(string data, linkedList* ref);

    Node* del(string data) {
        Node* temp;
        if (this->data == data) {
            temp = this->next;
            delete this;
            return temp;
        } else {
            temp = this;
            while (temp->next != NULL && temp->next->data != data) {
                temp = temp->next;
            }
            Node* tobeDel = temp->next;
            temp->next = temp->next->next;
            delete tobeDel;
            return this;
        }
    }

    bool search(string data) {
        Node* temp = this;
        while (temp && temp->data != data) {
            temp = temp->next;
        }
        if (temp) {
            return true;
        } else {
            return false;
        }
    }

    void display() {
        Node* temp = this;
        while (temp) {
            cout << " -> " << temp->data;
            temp = temp->next;
        }
    }
};

class linkedList {
    Node* root;
    string data;

   public:
    bool visited;
    linkedList();
    linkedList(string data);
    bool insertAdjacent(stack* s);
    string getData();
    void insert(string data, linkedList* ref);
    void del(string data);
    bool search(string data);
    void display();
};

#endif /* LIST_ */
