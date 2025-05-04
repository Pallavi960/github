#include<iostream>
#include<queue>
using namespace std;

class Node{

    public:
    Node* left;
    Node* right;
    int data;
    
    Node(int val)
    {
        data=val;
        left=right=NULL;
    }

};

int hight_of_tree(Node* root)
{
    if(root==NULL)return 0;//base case

    int left=hight_of_tree(root->left);
    int right=hight_of_tree(root->right);

    return 1+max(left,right);
}

void Print_LeveOrder(Node* root)
{
    if(root==NULL)return ;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(q.size()>0)
    {
        Node* temp=q.front();
        q.pop();

        //TO PRINT EVERY LEVEL SAPRATLY
        if(temp==NULL)
        {
            if(!q.empty())
            {
                cout<<endl;
                q.push(NULL);
                continue;
            }
            else
            {
                break;
            }

            
        }

        cout<<temp->data<<" ";

        if(temp->left!=NULL)q.push(temp->left);
        if(temp->right!=NULL)q.push(temp->right);
    }
}

int count(Node* root)
{
    if(root==NULL)return 0;

    int left=count(root->left);
    int right=count(root->right);

    return left+right+1;
}

int sum(Node* root)
{
    if(root==NULL)return 0;

   int left_sum= sum(root->left);
   int right_sum=sum(root->right);

    return left_sum+right_sum+root->data;
}

int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);

    root->left->left=new Node(4);
    root->left->right=new Node(5);

    root->right->left=new Node(6);
    root->right->right=new Node(7);

     Print_LeveOrder(root);

    cout<<endl<<hight_of_tree(root)<<endl;

    cout<<"Totle nodes:"<<count(root)<<endl;
    int summ=0;

    cout<<"Sum is:"<< sum(root);
    return 0;
}
