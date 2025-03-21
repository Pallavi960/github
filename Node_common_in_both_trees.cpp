#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
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


void traversar(Node* root,vector<int>&node)
{
    if(root==NULL);
    node.push_back(root->data);
    if(root->left!=NULL)traversar(root->left,node);
    if(root->right!=NULL)traversar(root->right,node);
}



void get(Node* root,vector<int>&node,vector<int>&ans)
{
    if(root==NULL);
    auto it=std::find(node.begin(),node.end(),node.data);
    if(it=ans.end())ans.push_back(root->data);
    if(root->left!=NULL)traversar(root->left,node);
    if(root->right!=NULL)traversar(root->right,node);
}





int main()
{
    //tree 1
    Node * root=new Node(1);//

    root->left=new Node(2);
    root->left->right=new Node(3);
    root->left->left=new Node(4);

    root->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);


    //tree 2
    Node* root2=new Node(1);

    root2->left=new Node(2);
    root2->right=new Node(3);

    root2->left->right=new Node(4);
    root2->left->left=new Node(5);
    root2->right->left=new Node(6);

    vector<int>nums;
    traversar(root,nums);

    get(root2,nums)
}
