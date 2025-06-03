#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;
    Node(int val)//constructor
    {
        data=val;
        right=left=NULL;
    }
};
Node* insert(Node* root,int val)
{
    if(root==NULL)
        return new Node(val);
    if(val<(root->data))//left(Small)
        root->left=insert(root->left,val);
    else//right grater
        root->right=insert(root->right,val);

    return root;
}


Node* BST(vector<int>&a)
{
    Node* root=NULL;
   for(int i=0;i<a.size();i++)
   {
       root=insert(root,a[i]);
   }
   return root;
}

void print(Node* root)//inorder sequence of BST is always in sorted manner
{
    if(root==NULL)return;
    print(root->left);
    cout<<root->data<<" ";//inorder traversal
    print(root->right);


}

int main()
{
    vector<int>a={3,2,1,5,6,4};
    Node* root=BST(a);
    print(root);
    return 0;
}
