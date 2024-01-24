/*

Author : Moniruzzaman Porag
Date of Creation: 23 January 2024

           ########################
           # Breadth First Search #
           ########################
-----------------
Time Complexity:
-----------------
Total number of Nodes = V;
Total number of Edges =E;

Time Complexity = O(V+E);

------------------
Space Complexity: O(V)
------------------


*/


#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int visited[N];
vector<int> adj_list[N];
void BFS(int src)
{
    queue<int> q;
    visited[src] = 1;
    q.push(src); //Push the source node to the queue 
    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        cout << head << endl;  //Output the current head Node
        for (int adj_node : adj_list[head]) // Explore all adjacent node of the current Node;
        {
            if (visited[adj_node] == 0)
            {
                visited[adj_node] = 1;
                q.push(adj_node); //Push the adjacent nodes to the queue;
            }
        }
    }
}
int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int src;
    cout<<"Enter the source node of the Graph : ";
    cin>>src;
    BFS(src);
}