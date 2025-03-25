#include<iostream>
#include<vector>
using namespace std;
struct Node{
    int data;
    Node* right;
    Node* left;
    Node(int val)
    {
        data=val;
        right=left=NULL;
    }
};
bool get_node(Node* root,int x,vector<int>&arr)
{
    if(root==NULL)return false;

    arr.push_back(root->data);//if get then return true
    if(root->data==x)return true;
    if(get_node(root->left,x,arr)|| get_node(root->right,x,arr))return true;//if atleast one is true then return true

       arr.pop_back();//not need element
       return false;


}

int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);

    vector<int>ans;
    get_node(root,56,ans);

        for(auto it:ans)
            cout<<it<<" ";
}

/*      1
       / \
      2   3
     / \ /
    4  5 6

*/

