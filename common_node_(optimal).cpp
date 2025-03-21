#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

//top view and bottom view of the binary tree
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

 void preorder(Node* root,map<int,int>&ans)
    {
        if(root==NULL)return ;
        preorder(root->left,ans);
        preorder(root->right,ans);
        ans[root->data]++;

    }


int main()
{
    Node * root1=new Node(1);//

    root1->left=new Node(2);
    root1->left->right=new Node(3);
    root1->left->left=new Node(4);

    root1->right=new Node(5);
    root1->right->left=new Node(6);
    root1->right->right=new Node(7);


    Node* root2=new Node(1);//

    root2->left=new Node(2);
    root2->left->right=new Node(3);
    root2->left->left=new Node(4);

    root2->right=new Node(5);
    root2->right->left=new Node(6);
    root2->right->right=new Node(7);

    vector<int>common;
    map<int,int>mpp;
    preorder(root1,mpp);
    preorder(root2,mpp);

    for(auto it:mpp)
    {
        if(it.second>1)
        {
            common.push_back(it.first);
        }

    }
    cout<<"Using optimal approch:";
    for(int i=0;i<common.size();i++)
    {
        cout<<common[i]<<" ";
    }
    return 0;

}
