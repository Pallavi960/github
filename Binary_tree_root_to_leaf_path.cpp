#include<iostream>
#include<vector>
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
void sol(Node* root,vector<string>&ans,string path)
{
if(root->left==NULL && root->right==NULL)
   {
    ans.push_back(path);
    return;//break recursion
   }
   if(root->left) sol(root->left,ans,path+"->"+to_string(root->left->data));//add string in appropriate format
   if(root->right) sol(root->right,ans,path+"->"+to_string(root->right->data));
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->left->left=new Node(4);
    vector<string>ans;
    string s=to_string(root->data);
     sol(root,ans,to_string(root->data));
     for(int i=0;i<ans.size();i++)
     {
         cout<<ans[i];//print string vector
     }

    return 0;
}
