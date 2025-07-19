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
    int start,end;
    for(int i=0;i<edges;i++)
    {
        cin>>start>>end;
        adj_matrix[start][end]=1;//ex: only 0-1 possible 1-0 is not possible

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
