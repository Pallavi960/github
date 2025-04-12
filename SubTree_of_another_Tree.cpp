#include<iostream>
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

bool is_identical(Node* root1,Node* root2)
{
    // if(root1==NULL && root2!=NULL || root1!=NULL && root2==NULL)
    // {
    //    return false; 
    // }

    // if(root1==NULL && root2==NULL)return true;

    //Alternatvi idea

    if(root1==NULL || root2==NULL)
    {
        return root1==root2;
    }

    return root1->data==root2->data && is_identical(root1->left,root2->left) && is_identical(root1->right,root2->right);

}

bool Issubtree(Node* root,Node* subroot)
{
    if(root==NULL || subroot==NULL)
    {
        return root==subroot;
    }
    if(root->data==subroot->data && is_identical(root,subroot))
    {
        return true;
    }
    
    return  Issubtree(root->left,subroot) || Issubtree(root->right,subroot);
}

int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);

    Node* subroot=new Node(2);
    subroot->left=new Node(4);
    subroot->right=new Node(5);

    if(Issubtree(root,subroot))cout<<"Yes";
    else
    cout<<"No";

    
 
    
    return 0;
}
