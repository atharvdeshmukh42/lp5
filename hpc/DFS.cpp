#include<iostream>
#include<vector>
#include<omp.h>

using namespace std;

vector<int> g[100];
bool v[100];

void dfs(int n)
{
    #pragma omp critical
    {
        if(v[n])
            return;

        v[n] = true;

        cout << n << " ";
    }

    #pragma omp parallel for
    for(int i = 0; i < g[n].size(); i++)
    {
        int x = g[n][i];

        if(!v[x])
        {
            dfs(x);
        }
    }
}

int main()
{
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v):" << endl;

    for(int i = 0; i < edges; i++)
    {
        int u, v;

        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u); // Undirected graph
    }

    int start;

    cout << "Enter starting vertex for DFS: ";
    cin >> start;

    cout << "\nDFS Traversal: ";

    dfs(start);

    return 0;
}