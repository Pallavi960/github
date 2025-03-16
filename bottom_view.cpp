#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;

//top view and bottom view of the binary tree
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



void Top_view(Node* root)
{
    map<int,int>mpp;
    vector<int>ans;
    if(root==NULL)return ;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            Node* dummy=q.front().first;
            auto it=q.front().second;
            q.pop();
            if(mpp.find(it)==mpp.end())
            {
                mpp[it]=dummy->data;//only first encounter node consider
            }
            if(dummy->left!=NULL)q.push({dummy->left,it-1});
            if(dummy->right!=NULL)q.push({dummy->right,it+1});

        }

    }

    for(auto it:mpp)
    {
        cout<<it.second<<" ";
    }
}

void Bottom_view(Node* root)
{
    if(root==NULL)return;
    queue<pair<Node*,int>>q;
    map<int,int>mpp;
    q.push({root,0});

    while(!q.empty())
    {

            Node* temp=q.front().first;
            auto it=q.front().second;
            q.pop();
            if(temp->left!=NULL)q.push({temp->left,it-1});
            if(temp->right!=NULL)q.push({temp->right,it+1});
            mpp[it]=temp->data;//cosider last node of every colum
    }
    for(auto it:mpp)
    {
        cout<<it.second<<" ";
    }

}



int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->left->right=new Node(5);
    root->right->right=new Node(10);

    Top_view(root);
    cout<<endl;

    Bottom_view(root);
    return 0;
}

/*     1
      / \
     2   3
    /     \
   4       10
    \
     5
*/

