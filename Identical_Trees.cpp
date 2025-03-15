#include<iostream>
#include<vector>
#include<stack>
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

//Three must important conditions
//if both roots are null(ENDS) at same time then it will be identical but need to check every node
//if on node NULL and other one is not null then no need to compare it will be never identical

//----IDENTICAL---- every left node data is same as every right node data
bool check(Node* root1,Node* root2)
{
    if(root1==NULL && root2==NULL)return true;
    if(root1==NULL || root2==NULL)return false;

    return (root1->data==root2->data) &&
    check(root1->left,root2->left) &&
    check(root1->right,root2->right);


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

    bool result=check(root1,root2);
    if(result==false)
    {
        cout<<" Tree is not Identical";
    }
    else{
        cout<<"Tree is identical";
    }
    return 0;
}


