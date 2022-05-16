#include <iostream>

using namespace std;

struct Node {
    string officeLocation = "";
    Node *next = NULL;
    Node *below = NULL;
    Node *original = NULL;
    bool isVisited = false;
    bool isOriginal = false;
    int distance = -1;
};


// int main() {
//     Node *n = new Node;

//     Node temp;

//     *n = temp;
// }
