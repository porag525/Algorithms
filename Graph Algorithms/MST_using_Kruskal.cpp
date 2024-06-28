#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int parent[N], sz[N];
void make(int v)
{
    parent[v] = v;
    sz[v] = 1;
}
int find(int v)
{
    if (parent[v] == v)
        return parent[v];
    return parent[v] = find(parent[v]);
}
void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
        if (sz[a] < sz[b])
            swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<pair<int,pair<int,int>>>edges;
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,{u,v}});
    }
    sort(edges.begin(),edges.end());
    for(int i=1;i<=n;i++)make(i);
    int total_cost=0;
    for(auto &edges:edges)
    {
        int wt=edges.first;
        int u=edges.second.first;
        int v=edges.second.second;
        if(find(u)==find(v))continue;
        Union(u,v);
        total_cost+=wt;
        cout<<u<<" "<<v<<endl;
    }
    cout<<total_cost<<endl;
}