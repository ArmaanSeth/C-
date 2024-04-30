#include<iostream>
#include<map>
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
    int sum(TreeNode* root,map<int,int> &m){
        if(root==NULL)
            return 0;
        if(m[root->val]!=0)
            return m[root->val];
        else{
            int a=root->val;
            a+=sum(root->right,m);
            a+=sum(root->left,m);
            m[root->val]=a;
            return m[root->val];
        }
    }
    void convert(TreeNode* &root,map<int,int> m){
        if(root==NULL)
            return;
        else{
            if(root->right==NULL)
                convert(root->left,m);
            else{
                root->val+=m[root->right->val];
                convert(root->right,m);
                convert(root->left,m);                    
            }
        }

    }
    TreeNode* convertBST(TreeNode* root) {
        map<int,int> m;
        sum(root,m);
        convert(root,m);
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
    node1->left=node3;
    node1->right=node4;
    node1->val=1;
    node->left=node1;
    node->right=node2;
    node->val=4;
    TreeNode* n=(TreeNode*)malloc(sizeof(TreeNode));
    string s="";
    Solution obj;
    n=obj.convertBST(node);
    display(n);
    return 0;
    }