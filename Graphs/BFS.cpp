#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void BFS(int v,vector<int>adjlist[])
{
   vector<int>ans;
   queue<int>q;
   vector<bool>visited(v,0);
   visited[0]=1;
   q.push(0);
   while(!q.empty())
   {
       int node=q.front();
       q.pop();
       ans.push_back(node);
       for(int i=0;i<adjlist[node].size();i++)
       {
           if(!visited[adjlist[node][i]])
           {
               visited[adjlist[node][i]]=1;
               q.push(adjlist[node][i]);
           }

       }

   }
   for(int i=0;i<ans.size();i++)
   {
       cout<<ans[i];
   }


}

int main()
{
    int nodes,edges;
    cout<<"Enter edges:";
    cin>>edges;
    cout<<"Enter nodes:";
    cin>>nodes;
    // for not weighted
    vector<int>adjlist[nodes];
    int a,b;
    for(int i=0;i<edges;i++)
    {
        cin>>a>>b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

/*for(int i=0;i<nodes;i++)
    {
        cout<<i<<"->";
        for(int j=0;j<adjlist[i].size();j++)
        {
            cout<<adjlist[i][j]<<" ";
        }
        cout<<endl;
    }


     for(int i=0;i<nodes;i++)
     {
         cout<<i<<"->";
         for(int j=0;j<adjlist[i].size();j++)
         {

             cout<<"("<<adjlist[i][j]<<" "<<adjlist[i][j]<<")";
         }
         cout<<endl;
     }
*/
     int start;
     cout<<"Enter start:";
     cin>>start;
     BFS(start,adjlist);


    return 0;

}
