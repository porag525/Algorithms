/*
->input a weighted  graph and a source.

Step-1: Create a distance array "d".
Step-2:Initialize all value of the distance  array "d" to  infinity.
Step3:Assign the distance of source to 0.d[src]=0;
Step-4:Create a visited array and mark all node as unvisited.
Step-5:Run a loop for all the node of the graph
Inside the  loop pic the unvisited and shortest distance node.
Mark the node as visited.
After that explore all the adjacent node of the node and perform
relaxation operetion.
Update the distace of a node when
d[node]+c(node,adj_node)<d[adj_node]
and then assign
d[adj_node]=d[node]+c(node,adj_node)
for i=0 to n-1
  -pick the "unvisited"  node with shortest d[node].
  -visited[node]=1;
  for all the adj_node of node
     -if
     d[node]+c(node,adj_node)<d[adj_node]
     d[adj_node]=d[node]+c(node,adj_node)

Now the distace arrry contain the distace of all node from the soure node.
Print the distance array.


*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
const int INF = 1e9;
int nodes, edges;
vector<pair<int, int>> adj_list[N];
int d[N];
int visited[N];

void Dijkstra(int src)
{
    for (int i = 1; i <= nodes; i++)
    {
        d[i] = INF;
    }
    d[src] = 0;

    for (int i = 0; i < nodes; i++)
    {
        int selected_node = -1;
        for (int j = 0; j < nodes; j++)
        {
            if (visited[j] == 1)
                continue;
            if (selected_node == -1 || d[selected_node] > d[j])
            {
                selected_node = j;
            }
        }
        visited[selected_node] = 1;
        for (pair<int, int> adj_entry : adj_list[selected_node])
        {
            int adj_node = adj_entry.first;
            int edge_cost = adj_entry.second;
            if (d[selected_node] + edge_cost < d[adj_node])
            {
                d[adj_node] = d[selected_node] + edge_cost;
            }
        }
    }
}
int main()
{

    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    Dijkstra(1);
    for (int i = 0; i < nodes; i++)
    {
        cout << d[i] << " ";
    }
}