/*

Author : Moniruzzaman Porag
Date of Creation: 23 January 2024

           ########################
           # Depth First Search #
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
stack<int>s;
vector<int> adj_list[N];
void DFS(int node)
{
    visited[node] = 1;
    for (int adj_node : adj_list[node])
    {
        if (visited[adj_node] == 0)
        {
            DFS(adj_node);
        }
    }
    s.push(node);
}
void topological_sort(int n)
{
   
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            DFS(i);
        }
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();

    }
}
int main()
{
    int nodes, edges;
    cout<<"Enter the number of nodes and edges : ";
    cin >> nodes >> edges;
    cout<<"Enter the egde list : "<<endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
    }
    cout<<"Topological Sorted Order : ";
    topological_sort(nodes);  
}