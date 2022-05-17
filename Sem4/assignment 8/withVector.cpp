#include <bits/stdc++.h>

using namespace std;

class Solution {
    void findTopoSort(int node, vector<int>& vis, stack<int>& st, vector<int> adj[]) {
        vis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                findTopoSort(it, vis, st, adj);
            }
        }
        st.push(node);
    }

   public:
    vector<int> topoSort(int N, vector<int> adj[]) {
        stack<int> st;
        vector<int> vis(N, 0);
        for (int i = 0; i < N; i++) {
            if (vis[i] == 0) {
                findTopoSort(i, vis, st, adj);
            }
        }
        vector<int> topo;
        while (!st.empty()) {
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }
};

// { Driver Code Starts.
int main() {
    cout << "\n Enter number of nodes:";

    int N;
    cin >> N;

    char ans;
    vector<int> adj[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "\n is there edge from" << i << "to" << j << ":";
            cin >> ans;
            if (ans == 'y')
                adj[i].push_back(j);
        }
    }

    Solution obj;
    vector<int> res = obj.topoSort(N, adj);

    cout << "Toposort of the given graph is:" << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}