#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m; // 1-based indexing

    /* using matrix */
    int graph1[n + 1][n + 1] = {0}; // o(n*n=n^2)
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // u->v, v->u
        graph1[u][v] = 1;
        graph1[v][u] = 1;   // for weight graph, store weight instead of 1
        /*  o(n) */
    }

    /* using list */
    vector<int> graph2[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // uth node contain edge between v, and vica-versa (only for undirected graph)
        graph2[u].push_back(v);
        graph2[v].push_back(u); // o(2E) // for directed graph, this part not required - o(E)
    }
    return 0;
}