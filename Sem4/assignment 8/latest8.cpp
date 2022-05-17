#define MAX 50
#include <iostream>
#include<vector>
using namespace std;
 int n;
class stack
{
	public:
		int data[MAX];
		int top=-1;
	public:
		bool empty()
		{
			if(top==-1)
			{
				return true;
			}
			return false;
		}
		void push(int x)
		{
			top++;
			data[top]=x;
		}
		void pop()
		{
			int x=data[top];
			top--;
		}
		
};
class Solution {
  void findTopoSort(int node, int vis[], stack & st, int **arr) {
    vis[node] = 1;
    int i=*arr[node];
    while(i){
      if (!vis[*arr[i]]) {
        findTopoSort(*arr[i], vis, st, arr);
      }
      i=*arr[node++];
    }
    st.push(node);
  }
  public:
    int * topoSort(int N, int **arr ) {
      stack st;
      // vector < int > vis(N, 0);
      int visit[N];
      for(int i=0;i<N;i++)
      {
        visit[i]=0;
      }
      for (int i = 0; i < N; i++) {
        if (visit[i] == 0) {
          findTopoSort(i, visit, st, arr);
        }
      }
      // vector < int > topo;
      int topo[N];
      while (!st.empty()) {
        // topo.push_back(st.data[st.top]);
        for(int i=0;i<N;i++)
        {
          topo[i]=st.data[st.top];
        }
        st.pop();
      }
      return topo;

    }
};

int main() {
 int N ;
cout<<"\n Enter number of nodes:";
cin>>N;
  char direc;
    int v[N];
    for(int i=0;i<N;i++)
            {
                cout<<"\n Enter node:";
                cin>>v[i];
            }
  int **adj = new int*[N];
    for(int i=0;i<N;i++)
    {
      adj[i] = new int[N];
        for(int j=0;j<N;j++)
        {
            cout<<"\n Is "<<v[i]<<" to "<<v[j]<<" a connection(y/n):";
                    cin>>direc;
                    if(direc=='y')
                    {
                        
                        adj[i][j] = 1;
                    }
                    
        }
    }
  n=N;

  Solution obj;
  int *return1 = obj.topoSort(6, adj);

  cout << "Topological sort of the given graph is:" << endl;
  for (int i = 0; i < N; i++) {
    cout << return1[i] << " ";
  }

  return 0;
} 