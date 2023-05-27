#include<bits/stdc++.h>

using namespace std;


void dfs(vector<vector<int>> graph, vector<bool> &visited, int start) {

    cout<<start<<endl;
    for(int i = 0; i < graph[start].size(); i++) {
        if(!visited[graph[start][i]]) {
            visited[graph[start][i]] = true;
            dfs(graph, visited, graph[start][i]);
        }
    }

    return;
}

void bfs(vector<vector<int>> &graph, vector<bool> &visited,  queue<int> &q) {
    if(q.size() == 0) {
        return;
    }
    if(!q.empty()) {
        int s = q.size();
        for(int i = 0; i < s; i++) {
            int front = q.front();
            cout<<front<<endl;
            // ited[front] = true;
            q.pop();
            for(auto it: graph[front]) {
                if(!visited[it]){
                    visited[it] = true;
                    q.push(it);
                }
            }
        }
    }
    bfs(graph, visited, q);
    return;
}

int main() {

    int n;
    cout<<"Enter Number Of Nodes: "<<endl;
    cin>>n;
    vector<vector<int>> graph(n+1);
    cout<<"Enter Edges: "<<endl;
    bool isExit = false;
    while(!isExit) {
        cout<<"Enter Source Node: "<<endl;
        int s, d;
        cin>>s;
        cout<<"Enter Destination Node:"<<endl;
        cin>>d;
        graph[s].push_back(d);
        cout<<"Do you wanna continue? (y/n)"<<endl;
        char ch;
        cin>>ch;
        if(ch == 'n') {
            isExit = true;
        }
    }


    cout<<"DFS::"<<endl;
    vector<bool> visited(n+1, false), visited2(n+1, false);
    dfs(graph, visited, 1);

    queue<int> q;
    q.push(1);
    cout<<"BFS::"<<endl;
    bfs(graph, visited2, q);
    return 0;
}
