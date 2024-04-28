#include<bits/stdc++.h>
#include<omp.h>

using namespace std;

class Graph {
    int v;
    vector<vector<int>> adj;

    public:
    Graph(int v) {
        this->v = v;
        adj.resize(v);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs() {
        int source = 0;
        vector<bool> visited(adj.size(), false);
        stack<int> s;

        visited[source] = true;
        s.push(source);

        while(!s.empty()) {
            int top = s.top();
            s.pop();

            cout<<" "<<top;

            for (int i = 0; i < adj[top].size(); i++) {
                int ele = adj[top][i];
                if(!visited[ele]) {
                    s.push(ele);
                    visited[ele] = true;
                }
            }
        }
    }
    void parallelDFS() {
        int source = 0;
        vector<bool> visited(adj.size(), false);
        stack<int> s;

        s.push(source);
        visited[source] = true;

        while(!s.empty()) {
            int top;
            top = s.top();
            cout<<" "<<top;
            #pragma omp critical
                s.pop();

            #pragma omp parallel for
            for (int i = 0; i < adj[top].size(); i++) {
                int ele = adj[top][i];
                if(!visited[ele]) {
                    #pragma omp critical
                    {
                        s.push(ele);
                        visited[ele] = true;
                    }
                }
            }
        }
    }


    void bfs() {
        int source = 0;
        vector<bool> visited(v, false);
        visited[source] = true;

        queue<int> q;
        q.push(source);

        while(!q.empty()) {
            int front = q.front();
            q.pop();

            cout<<" "<<front;
            for(int i = 0; i < adj[front].size(); i++) {
                int ele = adj[front][i];
                if(!visited[ele]) {
                    q.push(ele);
                    visited[ele] = true;
                }
            }
        }
    }

    void parallelBFS() {
        int source = 0;
        vector<bool> visited(v, false);
        visited[source] = true;

        queue<int> q;
        q.push(source);

        while(!q.empty()) {
            int front;
                    front = q.front();
                    cout<<" "<<front;
                    #pragma omp critical
                        q.pop();
                    #pragma omp parallel for
                        for(int i = 0; i < adj[front].size(); i++) {
                            int ele = adj[front][i];
                            if(!visited[ele]) {
                                #pragma omp critical
                                    {
                                        q.push(ele);
                                        visited[ele] = true;
                                    }
                                }
                        }
        }
    }
};

int main() {
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    auto start = chrono::high_resolution_clock::now();
    cout<<"DFS =====> "<<endl;
    g.dfs();
    cout<<endl;
    auto end = chrono::high_resolution_clock::now();
    cout<<"Time Taken: "<<chrono::duration_cast<chrono::microseconds>(end - start).count()<<" Microseconds"<<endl;

    start = chrono::high_resolution_clock::now();
    cout<<"Parallel DFS =============>"<<endl;
    g.parallelDFS();
    cout<<endl;
    end = chrono::high_resolution_clock::now();
    cout<<"Time Taken: "<<chrono::duration_cast<chrono::microseconds>(end - start).count()<<" Microseconds"<<endl;

    start = chrono::high_resolution_clock::now();
    cout<<"BFS ======>"<<endl;
    g.bfs();
    cout<<endl;
    end = chrono::high_resolution_clock::now();
    cout<<"Time Taken: "<<chrono::duration_cast<chrono::microseconds>(end - start).count()<<" Microseconds"<<endl;


    start = chrono::high_resolution_clock::now();
    cout<<"Parallel BFS =============>"<<endl;
    g.parallelBFS();
    cout<<endl;
    end = chrono::high_resolution_clock::now();
    cout<<"Time Taken: "<<chrono::duration_cast<chrono::microseconds>(end - start).count()<<" Microseconds"<<endl;



    return 0;
}
