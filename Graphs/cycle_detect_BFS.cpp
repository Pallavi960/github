#include<iostream>
#include<vector>
#include<queue>
using namespace std;



bool BFS(vector<int>adj[],vector<int>&visited,int node)
{
    queue<pair<int,int>>q;
    q.push({node,-1});
     while(!q.empty())
     {
         int parent=q.front().second;
         int get_node=q.front().first;
         q.pop();
         for(int i=0;i<adj[get_node].size();i++)
         {
             if(adj[get_node][i]==parent)
             {
                 continue;
             }
             else if(visited[adj[get_node][i]]==1)
             {
                 return 1;
             }
             visited[adj[get_node][i]]=1;
             q.push({adj[get_node][i],get_node});

         }

     }
     return false;
}








int main()
{
    int nodes,edges;
    cout<<"Enter edges:";
    cin>>edges;
    cout<<"Enter nodes:";
    cin>>nodes;

     vector<pair<int,int>>adjlist[nodes];
     int a,b,c;
     for(int i=0;i<edges;i++)
     {
         cin>>a>>b>>c;
         adjlist[a].push_back(make_pair(b,c));
         adjlist[b].push_back(make_pair(a,c));
     }

     for(int i=0;i<nodes;i++)
     {
         cout<<i<<"->";
         for(int j=0;j<adjlist[i].size();j++)
         {

             cout<<"("<<adjlist[i][j].first<<" "<<adjlist[i][j].second<<")";
         }
         cout<<endl;
     }

  vector<int>visited;
  if(BFS(adjlist,visited,0))
  {

      cout<<"yes";
  }
  else{
    cout<<"no";
  }


    return 0;

}
