#include<iostream>
#include<iomanip>//for the use of setw
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

//Traversal of the Binary tree

struct Node{
    struct Node* left;
    struct Node* right;
    int data;
    Node(int val)
    {
        data=val;
        left=right=NULL;
    }

};

//Preorder Traversal with recursion
void Preorder_traversal(Node* root)//Root-Left-RIGHT
{

    if(root==NULL)//if the Node is empty
        return;
    //recursion
    cout<<setw(2)<<root->data<<" ";
    Preorder_traversal(root->left);
    Preorder_traversal(root->right);

}

//INorder Traversal with recursion
void Inorder_traversal(Node* root)//Left-root-right
{
    if(root==NULL)//if the Node is empty
        return;
    Inorder_traversal(root->left);
    cout<<setw(2)<<root->data<<" ";
    Inorder_traversal(root->right);

}

//Postorder Traversal with recursion
void Post_order_traversal(Node* root)//Left-Right-Root
{
    if(root==NULL)//if the Node is NULL
        return;
    Post_order_traversal(root->left);
    Post_order_traversal(root->right);
    cout<<setw(2)<<root->data<<" ";
}


//--------Level order Traverser--------------

void Level_order_Traversal(Node* root)
{
    if(root==NULL)
        return;

    queue<Node*>q;
    q.push(root);

    while(!q.empty())//untill Level is not complete we need to check left and right for every node
    {
    int n=q.size();//level
    for(int i=0;i<n;i++)
    {
        Node* node=q.front();
        cout<<setw(2)<<node->data<<" ";
        q.pop();

        if(node->left!=NULL)
        {
          q.push(node->left);
        }
        if(node->right!=NULL)
        {
          q.push(node->right);
        }
    }

    }

}


//------Iterative Preorder Traverser---(Root-Left-Right)-------

vector<int> Traversel(Node* root)//it is somewaht like Level order Traverser
{
    vector<int>ans;
    if(root==NULL)return ans ;
    stack<Node*>st;
    st.push(root);
    while(!st.empty())
    {
        Node* temp=st.top();
        ans.push_back(temp->data);
        st.pop();
        (temp->right!=NULL)?(st.push(temp->right)):void();
        (temp->left!=NULL)?(st.push(temp->left)):void();

    }
   return ans;

}

//------Iterative Postorder Traverser---(Left-Right-Root)----------

//When you reverse the preorder it become Right-Left-Root but we need Left-Right-Root so swap again Left-Right
vector<int> TraverseP(Node* root)//Ittrative Postorder solution
{

    vector<int>ans;
    if(root==NULL)return ans;

    stack<Node*>st;
    st.push(root);

    while(!st.empty())
    {
        Node* temp=st.top();
        ans.push_back(temp->data);
        st.pop();
        (temp->left!=NULL)?(st.push(temp->left)):void();
        (temp->right!=NULL)?(st.push(temp->right)):void();
    }

    reverse(ans.begin(),ans.end());//we get reverse ans so reverse it
    return ans;

}

//---------- Iterative INorder Traversal ----(Left-Root-Right)-------------
vector<int> Traverse_IN(Node* root)
{
    vector<int>ans;
    if(root==NULL)return ans;

    stack<Node*>st;
    Node* node=root;
    while(true)
    {

       if(node!=NULL)
       {
           st.push(node);
           node=node->left;//check for left
       }
       else
       {
            if(st.empty())break;//complete
            node=st.top();//pop from stak then check for next
            ans.push_back(node->data);
            st.pop();
            node=node->right;//go to check right
        }

    }
    return ans;

}


void Print_Solution(vector<int>&ans)
{
    for(int i=0;i<ans.size();i++)
    {
       cout<<setw(2)<<ans[i]<<" ";
    }
}


int main()
{
    Node * root=new Node(1);//

    root->left=new Node(2);
    root->left->right=new Node(3);
    root->left->left=new Node(4);

    root->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    //using function for traversal

    cout<<setw(26)<<"Pre order Traversal:";
    Preorder_traversal(root);
    cout<<endl<<endl;

    cout<<setw(26)<<"In order Traversal:";
    Inorder_traversal(root);
    cout<<endl<<endl;

    cout<<setw(26)<<"Post order Traversal:";
    Post_order_traversal(root);
    cout<<endl<<endl;

    cout<<setw(26)<<"Level order Traverser:";
    Level_order_Traversal(root);
    cout<<endl<<endl;

    vector<int>nums= Traversel(root);
    cout<<setw(26)<<"Iterative Traverser(pre):";
    Print_Solution(nums);
    cout<<endl<<endl;

    vector<int>nums1=TraverseP(root);
    cout<<setw(26)<<"Iterative Traverser(post):";
    Print_Solution(nums1);
    cout<<endl<<endl;

    vector<int>nums3=Traverse_IN(root);
    cout<<setw(26)<<"Iterative Traverser(in):";
    Print_Solution(nums3);
    cout<<endl<<endl;

    return 0;

}
