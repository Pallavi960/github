#include<iostream>
#include<vector>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int data;

    Node(int val)//constructor
    {
        data=val;
        left=right=NULL;
    }
};

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

static int idx=-1;
Node* Build_Tree( const vector<int>&preorder){
     idx++;
     if (idx >= nums.size() || nums[idx] == -1) {
        return NULL;
    }

     Node* root=new Node(nums[idx]);
     root->left=Build_Tree(nums);
     root->right=Build_Tree(nums);

     return root;

}
int main()
{
    vector<int>preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=Build_Tree(preorder);
    
    inorder(root);  
    return 0;
/*  
            1
           / \
          2   3
             / \
            4   5
*/
}