#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data=val;
        right=left=NULL;
    }
};

int left_hight(Node* root)//left hight
{
    int c=0;
    while(root)
    {
        root=root->left;
        c++;
    }
    return c;

}
int right_hight(Node* root)//right hight
{
    int c=0;
    while(root)
    {
        root=root->right;
        c++;
    }
    return c;
}

int count_N(Node* root)
{

    //when lh==rh it means all nodes are present
   int lh=left_hight(root);
   int rh=right_hight(root);
   if(lh==rh)return (1<<lh)-1;
   return 1+count_N(root->left)+count_N(root->right);
}



int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);

    root->left->left=new Node(4);
    root->left->right=new Node(5);

    root->right->left=new Node(6);
    root->right->right=new Node(7);
    cout<<count_N(root);
    return 0;
}
