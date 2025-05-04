#include<iostream>
#include<queue>
using namespace std;
struct Node{
    int data;
    Node* right;
    Node* left;
    Node(int val)
    {
        data=val;
        left=right=NULL;
    }
};

int get_width(Node* root)
{
        if(root==NULL)return 0;
        int ans=INT_MIN;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
           int n=q.size();
           int first,last,get=q.front().second;
           for(int i=0;i<n;i++)
           {
             Node* temp=q.front().first;
             int curr=q.front().second-get;
             q.pop();
             if(i==0)first=curr;
             if(i==n-1)last=curr;
             if(temp->left!=NULL)q.push({temp->left,(long long)2*curr+1});//avoide overflow
             if(temp->right!=NULL)q.push({temp->right,(long long)2*curr+2});//avoide overflow
           }
           ans=max(ans,last-first+1);
        }
        return ans;

}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->right->right=new Node(5);
    cout<<get_width(root);
    return 0;
}
