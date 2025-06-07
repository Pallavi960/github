#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* right;
    Node* left;
    Node(int val)//constructor
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
        if(curr->data>val)
        {
            //we need <= val
            curr=curr->left;
        }
        else
        {
            ans=curr->data;
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
     int ans=ceil(root,5);//4 is less then 5
     cout<<ans;
    return 0;
}
