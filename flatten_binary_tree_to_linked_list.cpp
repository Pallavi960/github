#include<iostream>
#include<stack>
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
void flatter(Node* root,Node* prev)
{
  if(root==NULL)return;
  while(root!=NULL)
  {

      if(root->left!=NULL)
      {
          prev=root->left;//here prev is the first node of left most
          Node* ip=prev;
          while(ip->right!=NULL)//right most node of left subtree
          {
              ip=ip->right;
          }
          ip->right=root->right;//first assign right to inorder precedence
          root->right=prev;//then assign root's right

          root->left=NULL;//to convert linked list,left alwas NULL


      }
      root=root->right;//if no left then go to right
  }
}
void print_nodes(Node* root)
{

    if(root==NULL){
        cout<<"NULL";
        return;
    };
    cout<<root->data<<" ";
    print_nodes(root->left);
    print_nodes(root->right);

}
int main()
{
    Node* root=new Node(1);
    root->left=new  Node(2);
    root->left->left=new Node(3);
    root->left->right=new Node(4);

    root->right=new Node(5);
    root->right->right=new Node(6);

    print_nodes(root);
    cout<<endl;
    Node* prev=NULL;
    flatter(root,prev);
    print_nodes(root);
    return 0;
}
