#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;


struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val)//constructor
    {
        data=val;
        left=right=NULL;
    }
};

int height(Node* root,int *maxi)
{
    if(root==NULL)return 0;

    int lefthight=height(root->left,maxi);
    int righthight=height(root->right,maxi);
    *maxi=max(*maxi,lefthight+righthight);

    return 1+max(lefthight,righthight);
}


int main()
{
    Node* root=new Node(1);//

    root->left=new Node(2);
    root->left->right=new Node(3);
    root->left->left=new Node(4);

    root->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    int maxi=0;
   int ans=height(root,&maxi);
    cout<<"diameter of the binary tree:"<<maxi;


    return 0;
}
/*
         1
        / \
       2   5
      / \ / \
     4  3 6  7



*/


