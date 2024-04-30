#include<iostream>
#include<math.h>
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
    TreeNode* rotation(TreeNode* root,int r,int l){
        if((fabs(l)-fabs(r))<=-2){
            TreeNode* temp=root->right;
            if(r<0){
                if(temp->left!=NULL){
                    root->right=temp->left;
                    temp->left=root;
                    root=temp;
                }
                else{
                    root->right=NULL;
                    temp->left=root;
                    root=temp;
                }
            }
            else if(r>0){
                temp=temp->left;
                TreeNode* temp2=new TreeNode,*temp3=new TreeNode;
                if(temp->left!=NULL)
                    temp2=temp->left;
                else
                    temp2=NULL;
                if(temp->right!=NULL)
                    temp3=temp->right;
                else
                    temp3=NULL;
                temp->right=root->right;
                temp->right->left=temp3;
                root->right=temp2;
                temp->left=root;
                root=temp;
            }
        }
        else if((fabs(l)-fabs(r))>=2){
            TreeNode* temp=root->left;
            if(l>0){
                if(temp->right!=NULL){
                    root->left=root->left->right;
                    temp->right=root;
                    root=temp;
                }
                else{
                    root->left=NULL;
                    temp->right=root;
                    root=temp;
                }
            }
            else if(l<0){
                temp=temp->right;
                TreeNode* temp2=new TreeNode,*temp3=new TreeNode;
                if(temp->left!=NULL)
                    temp2=temp->left;
                else
                    temp2=NULL;
                if(temp->right!=NULL)
                    temp3=temp->right;
                else
                    temp3=NULL;
                root->left->right=temp2;

                temp->left=root->left;
                root->left=temp3;
                temp->right=root;
                root=temp;
            }
        }
        return root; 
    }
    int diff(TreeNode* &root,int f=0){
        if(root==NULL)
            return 0;
        else{
            int r,l;
            if(root->right!=NULL && root->right->right==NULL && root->right->left==NULL)
                r=-1;
            else
                r=diff(root->right,-1);
            if(root->left!=NULL && root->left->right==NULL && root->left->left==NULL)
                l=1;
            else
                l=diff(root->left,1);
            if(fabs(fabs(r)-fabs(l))>=2){
                root=rotation(root,r,l);
                if(root->right!=NULL && root->right->right==NULL && root->right->left==NULL)
                    r=-1;
                else
                    r=diff(root->right,-1);
                if(root->left!=NULL && root->left->right==NULL && root->left->left==NULL)
                    l=1;
                else
                    l=diff(root->left,1);
                }
            if(fabs(l)==fabs(r)){
                return f*(fabs(l)+1);
            }
            return (fabs(r)>fabs(l))?-1*(fabs(r)+1):(fabs(l)+1);
        }
    }
    TreeNode* balanceBST(TreeNode* root) {
        diff(root);
        return root;
    }
};
void display(TreeNode* root){
    if(root==NULL){
        cout<<"null ";
        return;
    }
    cout<<root->val<<" ";
    display(root->left);
    display(root->right);
}
int main()
{
    system("cls");
    TreeNode *node=(TreeNode*)malloc(sizeof(TreeNode)),*node1=(TreeNode*)malloc(sizeof(TreeNode)),*node2=(TreeNode*)malloc(sizeof(TreeNode)),*node3=(TreeNode*)malloc(sizeof(TreeNode)),*node4=(TreeNode*)malloc(sizeof(TreeNode)),*node5=(TreeNode*)malloc(sizeof(TreeNode)),*node6=(TreeNode*)malloc(sizeof(TreeNode)),*node7=(TreeNode*)malloc(sizeof(TreeNode)),*node8=(TreeNode*)malloc(sizeof(TreeNode));
    node8->left=NULL;
    node8->right=NULL;
    node8->val=8;
    node7->left=NULL;
    node7->right=NULL;
    node7->val=3;
    node6->left=NULL;
    node6->right=NULL;
    node6->val=70;
    node5->left=NULL;
    node5->right=NULL;
    node5->val=85;
    node4->left=node6;
    node4->right=node5;
    node4->val=80;
    node3->left=NULL;
    node3->right=NULL;
    node3->val=100;
    node2->right=NULL;
    node2->left=NULL;
    node2->val=30;
    node1->left=node4;
    node1->right=node3;
    node1->val=90;
    node->left=node2;
    node->right=node1;
    node->val=60;
    TreeNode* n=(TreeNode*)malloc(sizeof(TreeNode));
    string s="";
    Solution obj;
    n=obj.balanceBST(node);
    display(n);
    return 0;
    }