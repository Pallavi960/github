#include<iostream>
#include<vector>
using namespace std;
class Solution {
    bool present( vector<vector<int>>&adj,vector<int>&visited,int start,int parent)
    {
        visited[start]=1;
        for(int i=0;i<adj[start].size();i++)
        {
            if(!visited[adj[start][i]])
            {
                bool cycle=present(adj,visited,adj[start][i],start);
                if(cycle)
                {
                    return true;
                }
            }
            else if(adj[start][i]!=parent)
            {
                return true;
            }
            else
            {
                continue;
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        // we can solve it using DFS and BFS
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);

        }
        vector<int>visited(V,0);
        for(int i=0;i<visited.size();i++)
        {
            if(visited[i]==0)
            {
                if(present(adj,visited,i,-1))
                {
                    return true;
                }
            }
        }
        return false;

    }
};
int main()
{

    vector<vector<int>>edges={{0, 1}, {1, 2}, {2, 3}};
    int  V = 4;
    Solution s;
    if(s.isCycle(V,edges))
    {
        cout<<"Present";
    }
    else
    {

        cout<<"Not present";
    }
return 0;
}
