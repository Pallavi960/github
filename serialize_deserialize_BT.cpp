#include<iostream>
#include<sstream>
#include<queue>
#include<string>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int n){
    data=n;
    left=right=NULL;
    }
};
void get(Node* root,string &s)
{

    if(root==NULL)return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node* curr=q.front();
        q.pop();
        if(curr!=NULL)
        {
            s+=to_string(curr->data)+',';
           q.push(curr->left);
            q.push(curr->right);

        }
        else
        {
            if(q.empty())
            {
                s.append("#");
            }
            else
            
            {
                s.append("#,");
            }
        }
    }
    cout<<s;

}

Node* deserilize(string ss)
{
    if(ss.size()==0)return NULL;
    stringstream s(ss);
    string str;
    getline(s,str,',');
    queue<Node*>q;
    Node* root=new Node(stoi(str));
    q.push(root);
    while(!q.empty())
    {
        Node* root=q.front();
        q.pop();
        getline(s,str,',');
        if(str !="#")
        {
            Node* leftNode=new Node(stoi(str));
            root->left=leftNode;
            q.push(leftNode);
        }
        else
        {
            root->left=NULL;
        }
         getline(s,str,',');
         if(str!="#")
        {
            Node* rightNode=new Node(stoi(str));
            root->right=rightNode;
            q.push(rightNode);
        }
        else
        {
            root->right=NULL;
        }

    }
    return root;


}
void print_tree(Node* root)
{

    if(root==NULL)return;
    print_tree(root->left);
    cout<<root->data<<" ";
    print_tree(root->right);
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);

    root->left->left=new Node(4);
    root->right->left=new Node(5);
    root->right->right=new Node(6);
    string s="";
    get(root,s);
    Node* get_root=deserilize(s);
    cout<<endl;
    print_tree(get_root);






    return 0;
}
