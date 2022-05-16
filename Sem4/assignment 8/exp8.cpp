#include <iostream>
#include "list.h"
#include "stack.h"
using namespace std;

Node::Node(string data, linkedList* ref) {
    this->data = data;
    this->next = NULL;
    this->ref = ref;
}

void Node::insert(string data, linkedList* ref) {
    Node* temp = this;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new Node(data, ref);
}

linkedList::linkedList() {}
linkedList::linkedList(string data) {
    this->root = NULL;
    this->data = data;
    this->visited = false;
}

bool linkedList::insertAdjacent(stack* s) {
    Node* temp = root;
    bool allvisited = true;
    while (temp != NULL) {
        if (!temp->ref->visited) {
            allvisited = false;
            temp->ref->visited = true;
            s->push(temp->ref);
            break;
        }
        temp = temp->next;
    }
    return !allvisited;
}

string linkedList::getData() {
    return this->data;
}
void linkedList::insert(string data, linkedList* ref) {
    if (root) {
        root->insert(data, ref);
    } else {
        root = new Node(data, ref);
    }
}

void linkedList::del(string data) {
    if (root) {
        root = root->del(data);
    }
}

bool linkedList::search(string data) {
    if (root) {
        return root->search(data);
    }
    return false;
}

void linkedList::display() {
    if (root) {
        root->display();
    }
    cout << endl;
}

stack::stack(int n) {
    this->n = n;
    this->list = new linkedList*[n];
    this->top = -1;
}
void stack::push(linkedList* node) {
    list[++top] = node;
}

bool stack::isEmpty() {
    return top == -1;
}
linkedList* stack::pop() {
    return list[top--];
}

linkedList* stack::peek() {
    return list[top];
}

stack::~stack() {
    delete[] list;
}

class Graph {
    linkedList* adjacency_list;
    stack* dfs_stack;
    int v;
    void resetVisited() {
        for (int i = 0; i < this->v; i++) {
            adjacency_list[i].visited = false;
        }
    }

   public:
    Graph(int n) {
        this->v = n;
        this->adjacency_list = new linkedList[n];
        this->dfs_stack = new stack(n);
    }
    void initialize() {
        string data;
        linkedList* temp;
        for (int i = 0; i < this->v; i++) {
            cout << "Enter the landmark name of node " << i + 1 << " : ";
            cin >> data;
            adjacency_list[i] = linkedList(data);
        }
        for (int i = 0; i < this->v; i++) {
            cout << "Enter the landmarks which are connected to " << adjacency_list[i].getData() << " (type null if none) : ";
            while (true) {
                cin >> data;  // Extra Computation
                if (data != "null") {
                    for (int j = 0; j < this->v; j++) {
                        if (data == adjacency_list[j].getData()) {
                            temp = adjacency_list + j;
                            break;
                        }
                    }
                    adjacency_list[i].insert(data, temp);
                }
                if (cin.peek() == '\n') {
                    break;
                }
            }
        }
    }
    void display() {
        for (int i = 0; i < this->v; i++) {
            cout << "|" << adjacency_list[i].getData() << "|";
            adjacency_list[i].display();
        }
    }

    void dfs_search() {
        int k = 0;
        string topoSort[v];
        linkedList* temp;
        bool flag = true;
        int index = -1;
        for (int i = 0; i < v; i++) {
            flag = true;
            for (int j = 0; j < v; j++) {
                if (adjacency_list[j].search(adjacency_list[i].getData()) && !adjacency_list[i].visited) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                if (index == -1) {
                    index = i;
                } else {
                    cout << adjacency_list[i].getData() << " >>> ";
                }
            }
        }
        if (!adjacency_list[index].visited) {
            adjacency_list[index].visited = true;
            dfs_stack->push(adjacency_list + index);
        }
        while (!dfs_stack->isEmpty()) {
            temp = dfs_stack->peek();
            if (!temp->insertAdjacent(dfs_stack)) {
                temp = dfs_stack->pop();
                topoSort[k++] = temp->getData();
            }
        }
        for (int i = k - 1; i >= 0; i--) {
            cout << topoSort[i] << " >>> ";
        }

        cout << endl;
        resetVisited();
    }

    ~Graph() {
        delete[] adjacency_list;
        delete dfs_stack;
    }
};

int main() {
    int n;
    cout << "Enter the number of vertices in graph : ";
    cin >> n;
    Graph g(n);
    g.initialize();
    g.display();
    cout << "Topological sort of graph is defined as : ";
    g.dfs_search();
    return 0;
}
