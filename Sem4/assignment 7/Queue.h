#include "iostream"

using namespace std;

struct Node;

class Queue{
    int rear = -1, front = -1;
    int size;
    Node **queue;
    public:
    Queue(int size) {
        queue = new Node*[size];
        this->size = size;
    }

    void enQueue(Node *ele) {
        rear += 1;
        if(front == -1) {
            front += 1;
        }
        queue[rear] = ele;
    }

    Node* deQueue() {
        Node *temp = queue[front];
        // delete queue[front];
        ++front;
        if (front > rear) {
            front = -1;
            rear = -1;
        }
        return temp;
    }

    bool isEmpty() {
        if ( front > rear || front == -1 ||  rear == -1) {
            return true;
        }
        return false;
    }

    void printQueue();
};