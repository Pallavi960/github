#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data=val;
        left=right=NULL;
    }
};

int getSum(Node* root,bool check)
{
    if(root->left==NULL && root->right==NULL)//if it is leaf node then we consuider only left node
    {
        if(check)
        {
            return root->data;
        }
    }
    int sum=0;

    if(root->left!=NULL)
    {
        sum+=getSum(root->left,true);//true for left node
    }
    if(root->right!=NULL)
    {
        sum+=getSum(root->right,false);//false for right node
    }
    return sum;
}

int SumOfLeftLeave(Node* root)
{
    return getSum(root,false);//first node is not consider as left 
}

int main()
{
    Node* root=new Node(3);
    root->left=new Node(9);
    root->right=new Node(20);

    root->right->left=new Node(15);
    root->right->right=new Node(7);

    cout<<SumOfLeftLeave(root);
/*
        3
       / \
      9  20
        /  \
       15   7
*/
    return 0;
}
