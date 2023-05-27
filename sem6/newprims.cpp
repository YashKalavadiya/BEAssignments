#include<bits/stdc++.h>

using namespace std;

void prims(vector<vector<pair<int, int>>> &graph, vector<bool> &visited, int n) {
    vector<vector<pair<int, int>>> newGraph(n+1);

    visited[1] = true;
    int visitedCount = 1;
    while(visitedCount < n) {

        pair<int, int> minAdj;
        minAdj.second = INT_MAX;
        int from = -1;
        for(int i = 1; i < visited.size(); i++) {
            if(visited[i]) {
                for(int j = 0; j < graph[i].size(); j++) {
                    if(!visited[graph[i][j].first] and graph[i][j].second < minAdj.second) {
                        minAdj = graph[i][j];
                        from = i;
                    }
                }
            }
        }
        if(from != -1) {
            newGraph[from].push_back(minAdj);
            int temp = minAdj.first;
            minAdj.first = from;
            newGraph[temp].push_back(minAdj);
            visitedCount += 1;
            visited[temp] = true;
        }
    }

    cout<<"MST is: ------------>"<<endl;

    for(int i = 1; i < newGraph.size(); i++) {
        cout<<"| "<<i<<" ";
        for(int j = 0; j < newGraph[i].size(); j++) {
            cout<<" ->"<<newGraph[i][j].first<<"("<<newGraph[i][j].second<<")";
        }
        cout<<endl;
    }
}

int main() {

    int n;
    cout<<"Enter Nodes in graph: "<<endl;
    cin>>n;

    vector<vector<pair<int, int>>> graph(n+1);
    vector<bool> visited(n+1, false);

    bool isExit = false;

    while(!isExit) {
        cout<<"source: "<<endl;
        int s, d;
        cin>>s;
        cout<<"dest: "<<endl;
        cin>>d;
        int cost;
        cout<<"COST: "<<endl;
        cin>>cost;
        pair<int, int> p;
        p.first = d;
        p.second = cost;
        graph[s].push_back(p);

        p.first = s;
        graph[d].push_back(p);

        char c;
        cout<<"Continue ? (y/n)"<<endl;
        cin>>c;
        if(c == 'n') {
            isExit = true;
        }
    }
    cout<<"Graph is: ------------>"<<endl;

    for(int i = 1; i < graph.size(); i++) {
        cout<<"| "<<i<<" ";
        for(int j = 0; j < graph[i].size(); j++) {
            cout<<" ->"<<graph[i][j].first<<"("<<graph[i][j].second<<")";
        }
        cout<<endl;
    }

    prims(graph, visited, n);
}
