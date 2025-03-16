#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {

        data=val;
        left=right=NULL;
    }
};


void Level_order(Node* root)
{
    map<int,int>mpp;
    if(root==NULL)return ;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            Node* dummy=q.front().first;
            auto it=q.front().second;
            q.pop();
            mpp[it]=dummy->data;//the only diffrence between Top view ans bottom view
            if(dummy->left!=NULL)q.push({dummy->left,it-1});
            if(dummy->right!=NULL)q.push({dummy->right,it+1});

        }

    }

    for(auto it:mpp)
    {
        cout<<it.second<<" ";
    }
}



int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->left->right=new Node(5);

    Level_order(root);
    return 0;
}

