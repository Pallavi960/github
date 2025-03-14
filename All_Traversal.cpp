#include<iostream>
#include<vector>
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


void print(vector<int>nums)
{
    for(int i=0;i<nums.size();i++)
    cout<<nums[i]<<" ";
    cout<<endl;
}


void Traverse(Node* root)
{
    vector<int>Preorder;
    vector<int>Postorder;
    vector<int>Inorder;

    if(root==NULL)return ;
    stack<pair<Node*,int>>st;
    st.push({root,1});
    while(!st.empty())
    {
        auto it=st.top();
        st.pop();
        if(it.second==1)//preorder
        {
            Preorder.push_back(it.first->data);
            it.second++;
            st.push(it);
            Node* temp=it.first;
            if(temp->left!=NULL)st.push({temp->left,1});
            //goto left
        }
        else if(it.second==2)//inorder
        {
            Inorder.push_back(it.first->data);
            it.second++;
            st.push(it);
            Node* temp=it.first;
            if(temp->right!=NULL)st.push({temp->right,1});
        }
        else{
            Postorder.push_back(it.first->data);
        }

    }
    cout<<"Preorder:";print(Preorder);
    cout<<"Postorder:";print(Postorder);
    cout<<"Inorder:";print(Inorder);

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


    Traverse(root);
    return 0;
}
 /*1  2  4  3  5  6  7

       In order Traversal: 4  2  3  1  6  5  7

     Post order Traversal: 4  3  2  6  7  5  1*/
