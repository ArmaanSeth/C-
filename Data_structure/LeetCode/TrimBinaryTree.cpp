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
    TreeNode* trimBST(TreeNode* root, int low, int high,int f=0) {
        if(root==NULL)
            return root;
        if(f==0){
            if(root->val>=low && root->val<=high){
                root->left=trimBST(root->left,low,high,-1);
                root->right=trimBST(root->right,low,high,1);
            }
            else if(root->val>high){
                if(root->left==NULL)
                    return NULL;
                root=root->left;
                root=trimBST(root,low,high,0);
            }
            else if(root->val<low){
                if(root->right==NULL)
                    return NULL;
                root=root->right;
                root=trimBST(root,low,high,0);
            }
        }
        else if(f==-1){
            if(root->val<low){
                if(root->right==NULL)
                    return NULL;
                root=root->right;
                root=trimBST(root,low,high,f);
            }    
            else
                root->left=trimBST(root->left,low,high,f);
        }
        else{
            if(root->val>high){
                if(root->left==NULL)
                    return NULL;
                root=root->left;
                root=trimBST(root,low,high,f);
            }
            else
                root->right=trimBST(root->right,low,high,f);
        }
    return root;
    }
};
void display(TreeNode* root){
    if(root==NULL){
        cout<<"null ";
        return;
    }
    display(root->left);
    cout<<root->val<<" ";
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
    node6->right=node8;
    node6->val=7;
    node5->left=NULL;
    node5->right=NULL;
    node5->val=5;
    node4->left=NULL;
    node4->right=node7;
    node4->val=2;
    node3->left=NULL;
    node3->right=NULL;
    node3->val=0;
    node2->right=node6;
    node2->left=node5;
    node2->val=6;
    node1->left=NULL;
    node1->right=NULL;
    node1->val=2;
    node->left=NULL;
    node->right=node1;
    node->val=1;
    TreeNode* n=(TreeNode*)malloc(sizeof(TreeNode));
    string s="";
    Solution obj;
    n=obj.trimBST(node,2,4);
    display(n);
    return 0;
    }