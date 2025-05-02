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

int  Solution(Node* root)
{
    if(root==NULL)return 0;//base case
    int left_sum=Solution(root->left);//get left
    int right_sum=Solution(root->right);//get right
    root->data+=left_sum+right_sum;//update
    return root->data;//return

}
void print(Node* root)//print inorder
{
   if(root==NULL)return;
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->right->right=new Node(6);
     print(root);
     cout<<endl;
    Solution(root);
    print(root);
    return 0;
}
