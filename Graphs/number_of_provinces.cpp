#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<int>adj[],int node,vector<int>&visited)
{
    visited[node]=1;
    cout<<node<<" ";
    for(int i=0;i<adj[node].size();i++)
    {
        if(!visited[adj[node][i]])
        {
            dfs(adj,adj[node][i],visited);
        }
    }
}


int main()
{
    int nodes,edges;
    cout<<"Enter nodes:";
    cin>>nodes;
    cout<<"Enter edges:";
    cin>>edges;

    int a,b;
    int count=0;
    vector<int>adj[nodes];
    for(int i=0;i<edges;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
      vector<int>visited(nodes,0);
    for(int i=0;i<nodes;i++)
    {
        if(!visited[i])
        {
            count++;
           dfs(adj,i,visited);

        }
    }
    cout<<endl;
    cout<<"number of  provinces:"<<count;
    return 0;
}
