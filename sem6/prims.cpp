#include<bits/stdc++.h>

using namespace std;


struct Node {

    int value;
    Node *next, *below;
    int cost;
};

void solve(map<int, Node*> adjList) {
    map<int, Node*> newAdj;
    vector<int> added;
    added.push_back(1);
    while(newAdj.size() != adjList.size()) {
        Node *minNode = new Node;
        minNode->value = INT_MAX;
        minNode->cost = INT_MAX;
        int adjOf = -1;
        for(auto it: added) {
            Node *ptr;
            ptr = adjList[it];
            while(ptr != NULL) {
                if(newAdj.find(ptr->value) == newAdj.end() && minNode->cost > ptr->cost) {
                    minNode->value = ptr->value;
                    minNode->cost = ptr->cost;
                    adjOf = it;
                }
                ptr = ptr->next;
            }
        }
        if(adjOf != -1) {
            added.push_back(minNode->value);
            if(!newAdj[adjOf]){
                newAdj[adjOf] = minNode;
            }
            else {
                Node *temp;
                temp = newAdj[adjOf];
                while(temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = minNode;
            }

            Node *loopback = new Node;
            loopback->value = adjOf;
            loopback->cost = minNode->cost;
            if(!newAdj[minNode->value]) {
                newAdj[minNode->value] = loopback;
            }
            else {
                Node *temp;
                temp = newAdj[minNode->value];
                while(temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = loopback;

            }
        }
    }


    cout<<"After applying Prims algorithm: "<<endl;

    for(auto it:newAdj) {
        Node *transport;
        transport = it.second;
        cout<<"|"<<it.first<<" -> ";
        while(transport != NULL) {
            if(transport->value == INT_MAX){
                transport = transport->next;
                continue;
            }
            cout<<transport->value<<" -> ";
            transport = transport->next;
        }
        cout<<"|"<<endl;
    }
}

int main() {
    int n;
    cout<<"Number Of nodes: "<<endl;
    cin>>n;
    map<int, Node*> adjList;

    for(int i = 0; i < n; i++) {
        adjList[i+1] = NULL;
    }

    cout<<"Enter Edges: "<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(i == j) {
                continue;
            }
            cout<<"Enter Cost between "<<i+1<<" <-> "<<j+1<<":";
            int cost;
            cin>>cost;
            if(!cost) {
                continue;
            }

            Node *adj = new Node;
            adj->value = j+1;
            adj->cost = cost;
            Node *adj2 = new Node;
            adj2->value = i+1;
            adj2->cost = cost;
            Node *hBus = NULL;
            hBus = adjList[i+1];
            bool isplaced1 = false, isplaced2 = false;
            if(hBus == NULL) {
                hBus = adj;
                adjList[i+1] = adj;
                isplaced1 = true;
            }
            while(!isplaced1 && hBus->next != NULL) {
                hBus = hBus->next;
            }
            if(!isplaced1) {
                hBus->next = adj;
            }

            Node *hBus2 = NULL;
            hBus2 = adjList[j+1];
            if(hBus2 == NULL) {
                hBus2 = adj2;
                adjList[j+1] = adj2;
                isplaced2 = true;
            }
            while(!isplaced2 && hBus2->next != NULL) {
                hBus2 = hBus2->next;
            }
            if(!isplaced2) {
                hBus2->next = adj2;
            }
        }
    }

    cout<<"GIVEN GRAPH:"<<endl;


    for(auto it: adjList) {
        Node *transport;
        transport = it.second;
        cout<<"|"<<it.first<<" -> ";
        while(transport != NULL) {
        cout<<transport->value<<"("<<transport->cost<<")"<<" -> ";
            transport = transport->next;
        }
        cout<<"|"<<endl;
    }

    solve(adjList);

    return 0;
}
