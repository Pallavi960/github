#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    Node* left;
    Node* right;
    int data;
    Node(int val)//constructor
    {
        data=val;
        left=right=NULL;
    }
};

int get_index(vector<int>&inorder,int target,int start,int ed)//find index
{
    for(int i=start;i<=ed;i++)
    {
        if(inorder[i]==target)
        {
            return i;
        }
    }
    return -1;
}
Node* tree(vector<int>&postorder,vector<int>&inorder,int ps,int* pe,int is,int ie)//function for construct tree
{

    if(is>ie || *pe <0)return NULL;//base condition
    Node* root=new Node(postorder[*pe]);

    int target=postorder[(*pe)--];

    int get=get_index(inorder,target,is,ie);
    root->right=tree(postorder,inorder,ps,pe,get+1,ie);
    root->left=tree(postorder,inorder,ps,pe,is,get-1);
    return root;
}

void print_nodes(Node* root)
{
    if(root==NULL)return;
    print_nodes(root->left);
    cout<<root->data<<" ";
    print_nodes(root->right);
}
int main()
{
    vector<int>postorder={5,6,4,9,2,3};//left right,root
    vector<int>inorder={5,4,6,3,2,9};//left root tight
    int  n=postorder.size()-1;

    Node* root=  tree(postorder,inorder,0,&n,0,5);//we need to pass by refrence
    print_nodes(root);

    return 0;
    
}
