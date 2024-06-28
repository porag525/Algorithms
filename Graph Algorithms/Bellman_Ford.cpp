/*
Pseudocode:

Input->> A weighted graph and a source node(with no negative cycle)
Output->>Shortest distance from the source node to all  other node.

-Create a distace array "d" with all value to infinity.
-d[src]=0;

- for i=1 to n-1
   -for all edge e(u,v,w)
      -if d[u]+w <d[v]
        -d[v]=d[u]+w


-Print the distance array "d".
n--Number of nodes;
m--Number of edges.
-Time complexity -> O(n*m)
-Space complexity ->O(n).

*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
vector<pair<int, int>> adj_list[N];
int d[N];
int main()
{
   int n, m;
   cin >> n >> m;
   for (int i = 0; i < n; i++)
   {
      int u, v, w;
      cin >> u >> v >> w;
      adj_list[u].push_back({v, w});
      adj_list[v].push_back({u, w});
   }

   int src = 1;
   d[src] = 0;

   for (int i = 1; i <= n - 1; i++)
   {
      for (int node = 1; node <= n; node++)
      {
         for (auto adj_node : adj_list[node])
         {
            int u = node;
            int v = adj_node.first;
            int w = adj_node.second;

            if (d[u] + w < d[v])
            {
               d[v] = d[u] + w;
            }
         }
      }
   }

   for (int i = 1; i <= n; i++)
   {
      cout << d[i] << " ";
   }
}