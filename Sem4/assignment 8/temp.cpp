#include <iostream>
#include <queue>
using namespace std;

// Topological Sort
// GRAPH must be DAG (Directed Acyclic Graph)
// For a linear ordering for edge uv, u->v, u must be before v
// Step 1: Find the in-degree of each vertex
// Start from the vertex with in-degree 0
// Delete that element and all the outgoing edges
// Keep on repeating that process

// I am using Kahn's Algorithm (BFS)
// Time Complexity -> O(V+E)
// Space Complexity -> O(V) -> Use of Queue

class Node
{
private:
    int vertexNumber;
    Node *next;

public:
    Node()
    {
        vertexNumber = 0;
        next = nullptr;
    }
    Node(int n)
    {
        vertexNumber = n;
        next = nullptr;
    }
    friend class Graph;
};

class Graph
{
private:
    Node **adjList;
    bool *visitedList;
    int totalV;
    int totalE;

    void addEdge(int source, int destination)
    {
        Node *newnode = new Node(destination);
        newnode->next = adjList[source];
        adjList[source] = newnode;
    }

    void clear()
    {
        for (int i = 0; i < totalV; i++)
        {
            visitedList[i] = false;
        }
    }

public:
    Graph(int vertices, int edges)
    {
        totalE = edges;
        totalV = vertices;
        adjList = new Node *[vertices];
        visitedList = new bool[vertices];
        for (int i = 0; i < vertices; i++)
        {
            adjList[i] = nullptr;
            visitedList[i] = false;
        }
    }

    void create()
    {
        int source, destination;
        for (int i = 0; i < totalE; i++)
        {
            cout << "Enter Source and Destination \n";
            cout << "Source: ";
            cin >> source;
            cout << "Destination: ";
            cin >> destination;
            addEdge(source, destination);
        }
    }

    void display()
    {
        cout << "Graph is --> \n";
        for (int i = 0; i < totalV; i++)
        {
            if (adjList[i] == nullptr)
            {
                cout << "No connections for node " << i << " \n";
            }
            else
            {
                cout << "Node connected to " << i << " --> ";
                Node *temp = adjList[i];
                while (temp != nullptr)
                {
                    cout << temp->vertexNumber << " ";
                    temp = temp->next;
                }
                cout << "\n";
            }
        }
    }

    void topologicalSort()
    {
        // create an array which will store all the in-degree of vertices
        int indegree[totalV];
        for (int i = 0; i < totalV; i++)
        {
            indegree[i] = 0;
        }

        // calculating the indegree of vertices
        for (int i = 0; i < totalV; i++)
        {
            auto temp = adjList[i];
            while (temp != nullptr)
            {
                indegree[temp->vertexNumber]++;
                temp = temp->next;
            }
        }

        // displaying indegree of vertices
        cout << "Indegree of all vertices\n";
        for (int i = 0; i < totalV; i++)
        {
            cout << i << "-->" << indegree[i];
            cout << endl;
        }

        queue<int> queue;

        // enqueue all indegree 0 elements
        for (int i = 0; i < totalV; i++)
        {
            if (indegree[i] == 0)
            {
                queue.push(i);
            }
        }

        // create a array which will contain topological sorted elements
        int topologicalorder[totalV];
        for (int i = 0; i < totalV; i++)
        {
            topologicalorder[i] = 0;
        }

        // Topological Sort
        int count = 0;
        while (!queue.empty())
        {
            int vertex = queue.front();
            queue.pop();
            topologicalorder[count] = vertex;
            count++;
            auto temp = adjList[vertex];
            while (temp != nullptr)
            {
                indegree[temp->vertexNumber]--;
                if (indegree[temp->vertexNumber] == 0)
                {
                    queue.push(temp->vertexNumber);
                }
                temp = temp->next;
            }
        }

        cout << "Topological Sort:\n";
        for (int i = 0; i < totalV; i++)
        {
            cout << topologicalorder[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int vertices;
    int edges;
    cout << "Enter No of Vertices: ";
    cin >> vertices;
    cout << "Enter No of Edges: ";
    cin >> edges;
    Graph g1(vertices, edges);
    g1.create();
    cout << "\n\nGRAPH" << endl;
    g1.display();
    g1.topologicalSort();
    return 0;
}