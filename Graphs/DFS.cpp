#include<iostream>
#include<vector>
using namespace std;
void DFS(vector<int>adjlist[],vector<int>&visited,vector<int>&ans,int node)
{
    visited[node]=1;
    ans.push_back(node);
    for(int i=0;i<adjlist[node].size();i++)
    {
            if(!visited[adjlist[node][i]])
            {
                DFS(adjlist,visited,ans,adjlist[node][i]);
            }
        }
    }
int main()
{
    int nodes;
    int edges;

    cout<<"Enter nodes:";
    cin>>nodes;

    cout<<"Enter Edges:";
    cin>>edges;

    int a;
    int b;
    vector<int>adjlist[nodes];
    for(int i=0;i<edges;i++)
    {
        cin>>a>>b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    vector<int>ans;
    vector<int>visited(nodes,0);
    DFS(adjlist,visited,ans,0);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
