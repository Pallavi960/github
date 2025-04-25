#include<iostream>
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

Node* find_lca(Node* root,Node* a,Node* b)//function for LCA
{
    if (root == NULL) return NULL;

    if(root->data==a->data || root->data ==b->data)//if get lowet exactly
    {
        return  root;
    }
    Node* left_LCA=find_lca(root->left,a,b);//go to left subtree
    Node* right_LCA=find_lca(root->right,a,b);//ro to right subtree

    if(left_LCA && right_LCA)//both are valid means that is exactly LCA 
    {
        return root;
    }
    else if(left_LCA!=NULL)//one valid another not
    {
        return left_LCA;
    }
    else{
        return right_LCA;//no one valid
    }

}

int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);

    root->left->right=new Node(4);
    root->left->left=new Node(5);

    root->right->left=new Node(6);
    root->right->right=new Node(7);

    Node* a=root->left->right;
    Node* b=root->left;
    Node* get;
    get=find_lca(root,a,b);
    cout<<get->data;

    return 0;
}
