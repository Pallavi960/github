#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int nodes,edges;
    cout<<"Enter edges:";
    cin>>edges;
    cout<<"Enter nodes:";
    cin>>nodes;
    // for not weighted
    /*  vector<int>adjlist[nodes];
    int a,b;
    for(int i=0;i<edges;i++)
    {
        cin>>a>>b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    for(int i=0;i<nodes;i++)
    {
        cout<<i<<"->";
        for(int j=0;j<adjlist[i].size();j++)
        {
            cout<<adjlist[i][j]<<" ";
        }
        cout<<endl;
    }

    */
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


    return 0;

}
