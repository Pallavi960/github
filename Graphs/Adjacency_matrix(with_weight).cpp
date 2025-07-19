#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int edges,nodes;
    cout<<"Enter edges:";
    cin>>edges;
    cout<<"Enter node:";
    cin>>nodes;

    vector<vector<int>>adj_matrix(nodes,vector<int>(nodes,0));
    cout<<"Enter edges"<<endl;
    int start,end,weight;
    for(int i=0;i<edges;i++)
    {
        cin>>start>>end>>weight;
        adj_matrix[start][end]=weight;
        adj_matrix[end][start]=weight;
    }
    cout<<"Printing"<<endl;
    for(int i=0;i<nodes;i++)
    {
        for(int j=0;j<nodes;j++)
        {
            cout<<adj_matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
