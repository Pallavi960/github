#include<iostream>
#include<queue>
#include<algorithm>
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

//---using level order Traverser-----
int Level_order_Traversal(Node* root)
{
    int hight=0;
    vector<vector<int>>ans;
    if(root==NULL)return hight;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        hight++;
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            Node* temp=q.front();
            q.pop();
            if(temp->left!=NULL)q.push(temp->left);
            if(temp->right!=NULL)q.push(temp->right);
        }
    }
    return hight;
}

//----using recursion-------

int height(Node* root)
{

    if(root==NULL)return 0;
    return 1+max(height(root->left),height(root->right));
}

int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->left->left=new Node(5);
    root->left->left->left->left=new Node(6);

    int ans=Level_order_Traversal(root);
    cout<<"Hight of Binary tree using Level order Traverser:"<<ans<<endl;

    int ans1=height(root);
    cout<<"Hight of Binary tree using Recursion:"<<ans1;


    return 0;
}
