#include<iostream>
#include<vector>
using namespace std;

bool is_cysle_present(int node,int parent ,vector<int>&visited,vector<int>Adjlist[])
{
    visited[node]=1;
    for(int i=0;i<Adjlist[node].size();i++)
    {
        if(parent==Adjlist[node][i])//if it is parent the ignore it
        {
            continue;
        }
        if(visited[Adjlist[node][i]]==1)
        {
            return true;
        }
        if(is_cysle_present(Adjlist[node][i],node,visited,Adjlist)
           {
               return true;
           }
    }
    return false;
}


int main()
{
    int nodes;
    int edges;
    cout<<"Enter nodes:";
    cin>>nodes;
    cout<<"Enter edges:";
    cin>>edges;

    vector<int>Adjlist[nodes];
    int a,int b;
    for(int i=0;i<edges;i++)
    {
        Adjlist[a].push_back(b);
        Adjlist[b].push_back(a);
    }
    vector<int>visited;
    cout<<is_cysle_present(0,0,visited,Adjlist);


    return 0;
}
