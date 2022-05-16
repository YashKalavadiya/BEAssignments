#include <iostream>
// #include "Stack.h"
// #include "Queue.h"
// #include "Node.h"
#include "prims.h"

using namespace std;







class Graph {
    Node *originalGraph = NULL;
    // Node *primsTree;
    // Node *kruskalsTree;
    PrimsTree *pt;
    int size;
    // Stack *s;
    // Queue *q;
    public:
    Graph(int size) {
        this->size = size;
        originalGraph = new Node[size];
    }

    Node *nodeGenerator(int distance, string officeLocation) {
        Node *newNode = new Node;
        newNode->distance = distance;
        newNode->officeLocation = officeLocation;
        pt = new PrimsTree;
        return newNode;
    }


    bool areAllVisited() {
        bool areVisited = true;
        Node *current = originalGraph;
        while (current != NULL) {
            if (!current->isVisited) {
                return false;
            }
            current = current->below;
        }
        return true;
    }

    Node **getMinOfAllVisited(Node *current) {
        Node **ptr;
        ptr = (Node **)malloc(sizeof(Node *)*2);
        if(current->isVisited) {
            Node *min = pt->getMinimumAdjacent(current);
            Node *adjTo = current;
            while (current != NULL) {

                if(current->isVisited) {
                    Node *minAdj = pt->getMinimumAdjacent(current);
                    if (minAdj != NULL) {
                        if (min->distance > minAdj->distance){
                            adjTo = current;
                            min = minAdj;
                        }
                    }
                }
                current = current->below;
            }
            ptr[0] = min;
            ptr[1] = adjTo;

            return ptr;
        }
    }

    void primsMST(Node *start) {
        Node *current = start;

        pt->addNode(*(new Node), *current);
        current->isVisited = true;
        Node *toBeAdded = pt->getMinimumAdjacent(current);
        while (!areAllVisited()) {
            Node **pair = getMinOfAllVisited(start);
            Node *min, *adj;
            min = pair[0];
            adj = pair[1];
            pt->addNode(*adj, *min);
            min->original->isVisited = true;
        }
    }

    void insertNode() {
        cout<<"\nEnter Landmark: ";
        string landmark;
        cin>>landmark;
        Node *current = originalGraph;
        Node *newOffice = new Node;
        newOffice->officeLocation = landmark;
        newOffice->below = NULL;
        if(originalGraph->officeLocation == "") {
            originalGraph = newOffice;
	        return;
        }
        while (current->below != NULL) {
            if (current->officeLocation == newOffice->officeLocation) {
                cout<<"\nDuplicate Office!!!";
                return;
            }
            current = current->below;
        }
        current->below = newOffice;
    }

    void createEdge() {
        string loc1, loc2;
        int distance;
        cout<<"\nEnter Adjacent offices: ";
        cout<<"\nEnter location of Office 1: ";
        cin>>loc1;
        cout<<"\nEnter location of Office 2: ";
        cin>>loc2;
        cout<<"\nEnter distance of offices (KM):";
        cin>>distance;

        Node *office1 = nodeGenerator(distance, loc1);
        Node *office2 = nodeGenerator(distance, loc2);

        Node *transport1 = originalGraph, *transport2 = originalGraph;
        bool found = false;
        while(transport1->below != NULL && !found) {
            if(transport1->officeLocation == office1->officeLocation) {
                found = true;
                continue;
            }
            transport1 = transport1->below;
        }
        found = false;
        while(transport2->below != NULL && !found) {
            if (transport2->officeLocation == office2->officeLocation) {
                found = true;
                continue;
            }
            transport2 = transport2->below;
        }

        office1->original = transport1;
        office2->original = transport2;

        while(transport1->next != NULL) {
            if(transport1->officeLocation == office2->officeLocation) {
                cout<<"\nEdge Already exist!!!";
                delete office1;
                delete office2;
                return;
            }
            transport1 = transport1->next;
        }
        while(transport2->next != NULL) {
            if(transport2->officeLocation == office1->officeLocation) {
                cout<<"\nEdge Already exist!!!";
                delete office1;
                delete office2;
                return;
            }
            transport2 = transport2->next;
        }
        if (transport1->officeLocation == office2->officeLocation || transport2->officeLocation == office1->officeLocation) {
            delete office1;
            delete office2;
            cout<<"\nEdge Already exist!!!";
            return;
        }
        transport1->next = office2;
        transport2->next = office1;
    }
    

    void printGraph() {
        cout<<"\n----------------------------------------------\n";
        Node *current = originalGraph;
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

    void printMenu() {
        cout<<"\n=============================================";
        cout<<"\n1. Prims algorithm";
        cout<<"\n2. Kruskal's algorithm";
        cout<<"\n3. Print Graph (in adjacency list)";
        cout<<"\n4. Print Graph MST (Prim's)";
        cout<<"\n5. Print Graph MST (Kruskal's)";
        cout<<"\n6. Insert Node";
        cout<<"\n7. Create Edge";
        cout<<"\n8. Exit";
        cout<<"\n==============================================";
    }

    void exec() {
        for (int i = 0; i < size; i++) {
            insertNode();
        }
        char ch = 'y';
        cout<<"\n------------Enter Edges------------";
        while (ch == 'y') {
            createEdge();
            cout<<"\nDo you wanna continue? (y/n): ";
            cin>>ch;
        }

        bool isExit = false;
        while(!isExit) {
            printMenu();
            cout<<"\nEnter your choice: ";
            int ch;
            cin>>ch;
            switch(ch) {
                case 1:
                    primsMST(originalGraph);
                    pt->printPrimsTree();
                    break;
                case 2:
                    break;
                case 3:
                    printGraph();
                    break;
                case 4:
                    pt->printPrimsTree();
                    break;
                case 5:
                    break;
                case 6:
                    insertNode();
                    break;
                case 7:
                    // createEdge();
                    break;
                case 8:
                    isExit = true;
                    break;
                default:
                    cout<<"\nInvalid Choice!!!";
            }
        }
    }
};
int main() {
    cout<<"\nEnter Initial number of nodes: ";
    int size;
    cin>>size;
    Graph g(size);
    g.exec();
    return 0;
}
