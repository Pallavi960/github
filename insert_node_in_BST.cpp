#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* right;
    Node* left;
    Node(int val)
    {
        data=val;
        left=right=NULL;
    }
};
Node* insertIntoBST(Node* root, int val) {
        if(root==NULL)return new Node(val);
        Node* curr=root;
        while(curr!=NULL)
        {
            if(curr->data<val)
            {
                if(curr->right!=NULL)
                {
                    curr=curr->right;
                }
                else
                {
                    curr->right=new Node(val);
                    break;
                }
            }
            else
            {
                if(curr->left!=NULL)
                {
                    curr=curr->left;
                }
                else
                {
                    curr->left=new Node(val);
                    break;
                }
            }
        }
        return root;
    }


void InorderTraversal(Node* root)
{
    if(root==NULL)return;
    InorderTraversal(root->left);
    cout<<root->data<<" ";
    InorderTraversal(root->right);

}

int main()
{
    Node* root=new Node(4);
    root->left=new Node(2);
    root->left->left=new Node(1);
    root->left->right=new Node(3);
    cout<<"Before inserting node:";
    InorderTraversal(root);
    insertIntoBST(root,5);
    cout<<endl<<"After inserting node:";
    InorderTraversal(root);
    return 0;
}
