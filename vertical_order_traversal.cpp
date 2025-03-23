#include<iostream>
#include<vector>
#include<map>
#include<queue>
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

//in the vertical order traverrsal we need to give ans in such a way that it is sorted accordind to colum wise and as level wise also
//mutimap can store multiple values for multiple key inseted of multimap we can use multiset
vector<vector<int>> vertical_traversal(Node* root)
{
   vector<vector<int>>ans;
   map<int,multimap<int,int>>mpp;//here colum,level and it member
   if(root==NULL)return ans;
   queue<pair<Node*,pair<int,int>>>q;
   q.push({root,{0,0}});
   while(!q.empty())
   {
       int n=q.size();
       for(int i=0;i<n;i++)
       {
           Node* temp=q.front().first;

           int colum=q.front().second.first;
           int level=q.front().second.second;

           if(temp->left!=NULL)q.push({temp->left,{colum-1,level+1}});
           if(temp->right!=NULL)q.push({temp->right,{colum+1,level+1}});

           mpp[colum].insert({level,temp->data});//insert the data in map
           q.pop();
       }
   }
   vector<int>dummy;

   for(auto it:mpp)//first
   {
      vector<int>dummy;
      for(auto p:it.second)//take vector of the second
      {
          dummy.push_back(p.second);
      }
      ans.push_back(dummy);//addind vector in vector
   }
  return ans;


}

void print(vector<vector<int>>&ans)
{
    for(int i=0;i<ans.size();i++)
    {

        for(int j=0;j<ans[i].size();j++)
        {

            cout<<ans[i][j];
        }
        cout<<endl;
    }
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


    vector<vector<int>>nums=vertical_traversal(root);
    print(nums);
    return 0;
}

/*        1
         / \
        2   3
       / \ / \
      4  56   7
*/
