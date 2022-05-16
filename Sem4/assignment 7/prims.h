#include <iostream>
#include "Node.h"

using namespace std;

class PrimsTree {
    Node *adjList = NULL;

    public:
    bool checkIfExists(string officeLoc) {
        Node *current = adjList;
        while(current != NULL) {
            if (current->officeLocation == officeLoc) {
                return true;
            }
            current = current->below;
        }
        return false;
    }

    void linkNodes(Node adjOf, Node node, Node *original) {
        Node *current = adjList;

        Node *newNode = new Node;
        newNode->officeLocation = node.officeLocation;
        newNode->distance = node.distance;
        newNode->original = original;

        bool found = false;
        while(current != NULL and !found) {
            if(current->officeLocation == adjOf.officeLocation) {
                found = true;
                continue;
            }
            current = current->below;
        }

        if(current == NULL) {
            cout<<"\nInvalid Adjacent";
            return;
        }

        while(current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    void addNode(Node adjOf, Node node) {
        Node *newNode = new Node;
        newNode->officeLocation = node.officeLocation;
        // newNode->distance = node.distance;

        Node *current = adjList;
        if (current == NULL) {
            // current = newNode;
            adjList = newNode;
            return;
        }
        while(current->below != NULL) {
            current = current->below;
        }

        current->below = newNode;

        if(adjOf.officeLocation != "") {
            linkNodes(adjOf, node, current->below);
        }
    }

    void printGraph() {
        cout<<"\n----------------------------------------------\n";
        Node *current = adjList;
        while(current != NULL) {
            Node *horizontalTransport = current;
            while(horizontalTransport != NULL) {
                cout<<"| "<<horizontalTransport->officeLocation<<" ( "<<horizontalTransport->distance<<" )"<<" |->";
                horizontalTransport = horizontalTransport->next;
            }
            current = current->below;
            cout<<"NULL\n";
        }
    }

    Node* getMinimumAdjacent(Node *current) {
        if(current->next == NULL) {
            return NULL;
        }
        current = current->next;
        Node *min = new Node;
        min->distance = 9999;
        while(current != NULL) {
            if(current->distance < min->distance && !checkIfExists(current->officeLocation)) {
                min = current;
            }

            current = current->next;
        }
        if(checkIfExists(min->officeLocation)) {
            // cout<<"\n}}}}}}}}}}}}}}D ALREADY EXIST";
            return NULL;
        }
        return min;
    }

        void printPrimsTree() {
        cout<<"\n----------------------------------------------\n";
        Node *current = adjList;
        while(current != NULL) {
            Node *horizontalTransport = current;
            while(horizontalTransport != NULL) {
                cout<<"| "<<horizontalTransport->officeLocation<<" ( "<<horizontalTransport->distance<<" )"<<" |->";
                horizontalTransport = horizontalTransport->next;
            }
            current = current->below;
            cout<<"NULL\n";
        }
    }

};
