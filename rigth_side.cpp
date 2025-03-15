#include<iostream>
#include<vector>
#include<queue>
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

//Right side view
//Only the last element of the every row is visible
//Here we applied Level order Traverser and only store the last element of Every row
vector<int> Right_View(Node* root)
{
    vector<int>ans;
    if(root==NULL)return ans;

    queue<Node*>q;
    q.push(root);

    while(!q.empty())
    {
     int n=q.size();
     for(int i=1;i<=n;i++)
     {
        Node* temp=q.front();
        q.pop();

        if(temp->left!=NULL)q.push(temp->left);
        if(temp->right!=NULL)q.push(temp->right);

        if(i==n)ans.push_back(temp->data);
     }
    }

    return ans;

}

//In the Left side view the first element of the Every row is visible
vector<int> Left_View(Node* root)
{
    vector<int>ans;
    if(root==NULL)return ans;

    queue<Node*>q;
    q.push(root);

    while(!q.empty())
    {
     int n=q.size();
     int i=0;
     for(int i=1;i<=n;i++)
     {
        Node* temp=q.front();
        q.pop();
        if(temp->left!=NULL)q.push(temp->left);
        if(temp->right!=NULL)q.push(temp->right);
        //if(i==n)ans.push_back(temp->data);
        if(i==1)ans.push_back(temp->data);
     }
    }
    return ans;
}

void Print_solution(vector<int>ans)
{
    for(int i=0;i<ans.size();i++)
    {

        cout<<ans[i]<<" ";
    }
}
int main()
{
    Node* root=new Node(1);

    root->left=new Node(2);
    root->left->left=new Node(10);
    root->right=new Node(3);
    root->right->right=new Node(4);
    root->right->right->right=new Node(5);
    root->right->right->right->left=new Node(6);
    root->right->right->right->left->right=new Node(7);

    vector<int>nums=Right_View(root);
    cout<<"Right side view:";
    Print_solution(nums);
    cout<<endl;

    vector<int>nums2=Left_View(root);
    cout<<"Left side view:";
    Print_solution(nums2);


    return 0;
}

/*          1
           / \
          2   3
         /     \
        10      4
                 \
                  5
                 /
                6
                 \
                  7

 */
