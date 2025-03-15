#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
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

//zigzag Traversar(-----  left to right  ------- right to left------)
vector<vector<int>> ZigZag_LevelOrde(Node* root)
{
    vector<vector<int>>ans;
    if(root==NULL)return ans;

    queue<Node*>q;
    q.push(root);
    bool is=false;
    while(!q.empty())
    {
     int n=q.size();
     vector<int>dummy;
     for(int i=1;i<=n;i++)
     {
        Node* temp=q.front();
        q.pop();

        if(temp->left!=NULL)q.push(temp->left);
        if(temp->right!=NULL)q.push(temp->right);

        dummy.push_back(temp->data);
     }

     //just implement in Level order Traverser when you at odd Level reverse it
     if(!is)//true for odd
      reverse(dummy.begin(),dummy.end());

      ans.push_back(dummy);
      is=!is;//reset it for even
    }

    return ans;

}


void Print_solution(vector<vector<int>>ans)
{
    for(int i=0;i<ans.size();i++)
    {

        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<" "<<","<<" ";
    }
}
int main()
{
    Node* root=new Node(1);

    root->left=new Node(2);
    root->left->left=new Node(10);
    root->right=new Node(3);
    root->right->right=new Node(4);
    root->right->left=new Node(9);
    root->right->right->left=new Node(15);
    root->right->right->right=new Node(5);
    root->right->right->right->left=new Node(6);
    root->right->right->right->left->right=new Node(7);

    vector<vector<int>>nums=ZigZag_LevelOrde(root);
    cout<<"Zigzag traversal:";
    Print_solution(nums);
    cout<<endl;

    return 0;
}

/* Tree view
            1
           / \
          2   3
         /   / \
        10  9   4
               / \
              15   5
                 /
                6
                 \
                  7

 */

