#include<iostream>
#include<vector>
#include<queue>
#include<stack>
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

//left->data+right->data==root->data
bool check(Node* root)
{
    if(root==NULL)return true ;
    stack<Node*>st;
    st.push(root);
    while(!st.empty())
    {
        int right1=0,left1=0;
        Node* temp=st.top();
        st.pop();
        if(temp->right!=NULL){
            st.push(temp->right);
            right1=temp->right->data;
          }
        if(temp->left==NULL && temp->right==NULL)continue;
        if(temp->left!=NULL)
        {
          st.push(temp->left);
          left1=temp->left->data;
        }
       if((left1+right1)!=temp->data)return false;


    }
    return true;

}







int main()
{
    struct Node *root=new Node(2);
    root->left=new Node(3);
    root->right=new Node(1);
    root->left->right=new Node(5);
    root->left->left=new Node(8);
bool ans=check(root);
if(ans==1)cout<<"Yes";
        else
        cout<<"No";

}
