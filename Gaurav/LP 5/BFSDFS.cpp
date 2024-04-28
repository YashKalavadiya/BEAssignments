#include<iostream>
#include<omp.h>
#include<bits/stdc++.h>

using namespace std;

class Graph{
public:
    int vertices;
    vector<vector<int>> graph;
    vector<bool> visited;

    Graph(int v) : vertices(v), graph(v), visited(v, false) {}

    void addEdge(int a, int b){
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    void printGraph(){
        for(int i = 0; i < vertices; i++){
            cout << i << " -> ";
            for(auto j = graph[i].begin(); j != graph[i].end();j++){
                cout << *j << " ";
            }
            cout << endl;
        }
    }

    void initialize_visited(){
        visited.assign(vertices,false);
    }

    void dfs(int i){
        stack<int> s;
        s.push(i);
        visited[i] = true;

        while(s.empty() != true){
            int current = s.top();
            cout << current << " ";
            s.pop();
            for(int j = 0; j < graph[current].size(); j++){
                int neighbor = graph[current][j];
                if(visited[neighbor] == false){
                    s.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

    void parallel_dfs(int i){
        stack<int> s;
        s.push(i);
        visited[i] = true;

        while(s.empty() != true){
            int current = s.top();
            cout << current << " ";
            #pragma omp critical
                s.pop();
            
            #pragma omp parallel for
            for(int j = 0; j < graph[current].size(); j++){
                int neighbor = graph[current][j];
                if(visited[neighbor] == false){
                    #pragma omp critical
                    {
                        s.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
        }
    }

    void bfs(int i){
        queue<int> q;
        q.push(i);
        visited[i] = true;

        while(q.empty() != true){
            int current = q.front();
            q.pop();
            cout << current << " ";
            for(int j = 0; j < graph[current].size(); j++){
                int neighbor = graph[current][j];
                if(visited[neighbor] == false){
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

    void parallel_bfs(int i){
        queue<int> q;
        q.push(i);
        visited[i] = true;

        while(q.empty() != true){
            int current = q.front();
            cout << current << " ";
            #pragma omp critical
                q.pop();
            
            #pragma omp parallel for
            for(int j = 0; j < graph[current].size(); j++){
                int neighbor = graph[current][j];
                if(visited[neighbor] == false){
                    #pragma omp critical
                    {
                        q.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
        }
    }
};

int main()
{
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    Graph g(vertices);

    for (int i = 0; i < edges; i++) {
        int a, b;
        cout << "Enter edge " << i + 1 << " (source destination): ";
        cin >> a >> b;
        g.addEdge(a, b);
    }

    cout << "Adjacency List:\n";
    g.printGraph();

    int startNode;
    cout << "Enter the starting node for DFS and BFS traversals: ";
    cin >> startNode;

    cout << "Depth First Search: \n";
    auto start = chrono::high_resolution_clock::now();
    g.dfs(startNode);
    cout << endl;
    auto end = chrono::high_resolution_clock::now();
    cout << "Time taken: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

    cout << "Parallel Depth First Search: \n";
    g.initialize_visited();
    start = chrono::high_resolution_clock::now();
    g.parallel_dfs(startNode);
    cout << endl;
    end = chrono::high_resolution_clock::now();
    cout << "Time taken: "<< chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

    cout << "Breadth First Search: \n";
    g.initialize_visited();
    start = chrono::high_resolution_clock::now();
    g.bfs(startNode);
    cout << endl;
    end = chrono::high_resolution_clock::now();
    cout << "Time taken: "<< chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

    cout << "Parallel Breadth First Search: \n";
    g.initialize_visited();
    start = chrono::high_resolution_clock::now();
    g.parallel_bfs(startNode);
    cout << endl;
    end = chrono::high_resolution_clock::now();
    cout << "Time taken: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

    return 0;
}