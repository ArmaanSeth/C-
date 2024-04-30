#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* recursion(TreeNode* &root) 
    {
    if(root==NULL)
        {
        return root;
        }
    else
        {
        TreeNode* temp1=root->right;
        root->right=recursion(root->left);
        root->left=NULL;
        if(root->right==NULL)
            {
            root->right=recursion(temp1);
            }
        else
            {
            TreeNode* temp2=root;
            while(temp2->right!=NULL)
                {
                temp2=temp2->right;
                }
            temp2->right=recursion(temp1);
            }
        }
    return root;
    }
    void flatten(TreeNode* root) 
    {
    recursion(root);
    }
};
int main()
    {
    system("cls");
    TreeNode *head=new TreeNode,*a=new TreeNode,*b=new TreeNode,*c=new TreeNode,*d=new TreeNode,*e=new TreeNode,*linkedlist=new TreeNode;
    e->val=6;
    e->left=NULL;
    e->right=NULL;
    d->val=5;
    d->right=e;
    d->left=NULL;
    c->val=4;
    c->right=NULL;
    c->left=NULL;
    b->val=3;
    b->right=NULL;
    b->left=NULL;
    a->val=2;
    a->right=c;
    a->left=b;
    head->val=1;
    head->right=d;
    head->left=a;
    
    Solution obj;
    obj.flatten(head);
    return 0;
    }