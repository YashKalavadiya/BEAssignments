#include<bits/stdc++.h>

using namespace std;

#define N 3

struct Node {
    int cost;
    int level;
    Node* parent;
    int mat[N][N];
    int x, y;
};

void printMatrix(int mat[N][N]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

Node* newNode(int x, int y, int newX, int newY, int level, Node* parent, int mat[N][N]) {
    Node *node = new Node;
    copy(&mat[0][0], &mat[0][0] + N*N, &node->mat[0][0]);
    node->level = level;
    node->parent = parent;
    swap(node->mat[x][y], node->mat[newX][newY]);
    node->cost = INT_MAX;
    node->x = newX;
    node->y = newY;

    return node;
}

int row[] = {1, 0, -1, 0};
int col[] = {0, 1, 0, -1};


int calculateCost(int currentMat[N][N], int dest[N][N]) {
    int cost = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(currentMat[i][j] && currentMat[i][j] != dest[i][j]) {
                cost += 1;
            }
        }
    }

    return cost;
}

int isSafe(int x, int y) {
    return (x >= 0 && y >= 0 && x < N && y < N);
}

void printPath(Node* root) {
    if(root == NULL) {
        return;
    }
    printPath(root->parent);
    printMatrix(root->mat);
    cout<<endl;
}

struct comp {
    bool operator()(const Node* a, const Node* b) const {
        return (a->cost + a->level) > (b->cost + b->level);
    }
};


void solve(int initial[N][N], int dest[N][N], int x, int y) {

    priority_queue<Node*, vector<Node*>, comp> pq;

    Node *root = newNode(x, y, x, y, 0, NULL, initial);


    root->cost = calculateCost(initial, dest);

    pq.push(root);

    while(!pq.empty()) {
        Node *current = pq.top();
        pq.pop();

        if(current->cost == 0) {
            printPath(current);
            return;
        }
        for(int i = 0; i < 4; i++) {
            if(isSafe(current->x + row[i], current->y + col[i])) {
                Node *child = newNode(current->x, current->y, current->x + row[i], current->y + col[i], current->level + 1, current, current->mat);
                child->cost = calculateCost(child->mat, dest);
                pq.push(child);

            }
        }
    }
}

int main(){

    int initial[N][N], dest[N][N];
    cout<<"Enter Initial Matrix (0 for blank space): \n";

    int initX, initY;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            int temp;
            cin>>temp;
            if(temp == 0) {
                initX = i;
                initY = j;
            }
            initial[i][j] = temp;
        }
    }

    cout<<"Enter destinatio Matrix (0 for blank space): \n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            int temp;
            cin>>temp;
            dest[i][j] = temp;
        }
    }

    cout<<initX<<":"<<initY<<endl;
    solve(initial, dest, initX, initY);

    return 0;
}
