#
#include<iostream>
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
int ceil(Node* root,int val)
{
    if(root==NULL)return -1;//not get ceil
    Node* curr=root;
    int ans=-1;
    while(curr!=NULL)
    {
        if(curr->data==val)
        {
            ans=curr->data;
        }
        if(curr->data>val)
        {
            ans=curr->data;//we need >= val
            curr=curr->left;
        }
        else
        {
            curr=curr->right;
        }
    }
    return ans;
}

void InorderTraversal(Node* root)
{
    if(root==NULL)return;
    InorderTraversal(root->left);
    cout<<root->data<<" ";
    InorderTraversal(root->right);

}

int main()
{
    Node* root=new Node(4);
    root->left=new Node(2);
    root->left->left=new Node(1);
    root->left->right=new Node(3);
    cout<<"Before inserting node:";
     int ans=ceil(root,0);
     cout<<ans;
    return 0;
}
