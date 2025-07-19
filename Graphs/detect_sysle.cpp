#include<iostream>
#include<vector>
using namespace std;

bool cycle(vector<int>adj[],int parent,int start,vector<int>&visit)
{
    visit[start]=1;
    for(int i=0;i<adj[start].size();i++)
    {
        if(parent==adj[start][i])
        {
            continue;
        }
        else if(visit[adj[start][i]]==1)
        {
            return true;
        }
       if(cycle(adj,adj[start][i],start,visit))
       {
           return true;
       }

    }
    return false;
}


int main()
{
   int nodes,edges;
   cout<<"Edges;";
   cin>>edges;
   cout<<"Nodes:";
   cin>>nodes;

   vector<int>adj[nodes];
   int a,b;
   for(int i=0;i<edges;i++)
   {
       cin>>a>>b;
       adj[a].push_back(b);
       adj[b].push_back(a);
   }
    vector<int>visit;


   if(cycle(adj,0,0,visit))
   {

       cout<<"yes";
   }
   else
   {

       cout<<"No";
   }
}
