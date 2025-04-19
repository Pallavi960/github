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
void Solution(Node* root,int target)
{
   if(root==NULL)return ;
   if(target==1)//getting target
   {
       cout<<root->data;
      return;
   }
   Solution(root->left,target-1);
   Solution(root->right,target-1);



}
int main()
{
    Node* root=new Node(1);//first level
    root->left=new Node(2);//2 level
    root->right=new Node(3);//2 level

    root->left->left=new Node(4);//3 level
    root->right->right=new Node(5);//3level
     Solution(root,2);

    return 0;
}
