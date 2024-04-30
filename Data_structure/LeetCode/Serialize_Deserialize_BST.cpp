#include<iostream>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*class Codec {
public:
    void stringlist(TreeNode* root,int n,vector<string> &list){
        if(root==NULL){
            if(n<list.size())
                list[n]='n';
            return;
        }
        int k=root->val;
        string s="";
        while(k!=0){
            int temp=k%10;
            string str="";
            k=k/10;
            str='0'+temp;
            s=str[0]+s;
        }
        list[n]+=s;
        stringlist(root->right,2*n+2,list);
        stringlist(root->left,2*n+1,list);
    }
    int height(TreeNode* root){
        if(root==NULL)
            return 0;
        else{
            int a=1+height(root->right),b=1+height(root->left);
            return (a>b)?a:b;
        }
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        int h=height(root),l=0;
        string s="";
        if(h==0)
            return s;
        for(int i=0;i<h;i++){
            l+=pow(2,i);
        }
        vector<string> list(l,"");
        stringlist(root,0,list);
        
        for(int i=0;i<l;i++){
            s+=list[i];
            s+=',';
        }
        return s;
    }
    void insert(string data,int n,TreeNode*& root,int f){
        int k=0,i=0;
        for(i=0;i<data.length();i++)
            {
            if(data[i]==',')
                k++;
            }
        if(n>=k){
            if(f==0)
                root->left=NULL;
            else
                root->right==NULL;
            return;
        }
        else{
            TreeNode* node=(TreeNode*)malloc(sizeof(TreeNode));
            node->right=NULL;
            node->left=NULL;
            i=0;
            k=0;
            while(k!=n){
                if(data[i]==',')
                    k++;
                i++;
            }
            k=0;
            if(data[i]=='n'){
                if(f==0)
                    root->left=NULL;
                else
                    root->right==NULL;
                return;
            }
            while(data[i]!=','){
                k=10*k+data[i]-'0';
                i++;
            }
            if(f==0){
                node->val=k;
                insert(data,2*n+1,node,0);
                insert(data,2*n+2,node,1);
                root->left=node;
            }
            else{
                node->val=k;
                insert(data,2*n+1,node,0);
                insert(data,2*n+2,node,1);
                root->right=node;
            }
        }
    }
    TreeNode* deserialize(string data) {
        TreeNode *root=new TreeNode;
        if(data.length()==0)
            return NULL;
        int i=0,k=0;
        while(data[i]!=','){
            k=10*k+data[i]-'0'; 
            i++;
        }
        root->val=k;
        insert(data,1,root,0);
        insert(data,2,root,1);
        return root;
    }
};*/
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    string s="";
    if(root==NULL)
        return s;
    int k=root->val;
    if(k==0)
        s='0';
    while(k!=0){
        int temp=k%10;
        string str="";
        k=k/10;
        str='0'+temp;
        s=str[0]+s;
        }
    s+=',';
    s+=serialize(root->left);
    s+=serialize(root->right);
    return s;
    }
    void insert(TreeNode* root,int n){
        TreeNode* temp=(TreeNode*)malloc(sizeof(TreeNode)),*temp2=root;
        temp->val=n;
        temp->left=NULL;
        temp->right=NULL;
        if(root->val>n){
            if(root->left==NULL)
                root->left=temp;
            else
                insert(root->left,n);
        }
        else{
            if(root->right==NULL)
                root->right=temp;
            else
                insert(root->right,n);
        }
    }
    TreeNode* deserialize(string data) {
        TreeNode* root=NULL;
        for(int i=0;i<data.length();i++){
            int j=i;
            string s="";
            while(data[j]!=','){
                s+=data[j];
                j++;
            }
            i=j;
            if(s=="")
                break;
            j=stoi(s);
            if(root==NULL){
                TreeNode* temp=(TreeNode*)malloc(sizeof(TreeNode));
                temp->val=j;
                temp->left=NULL;
                temp->right=NULL;
                root=temp;
            }
            else
                insert(root,j);
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
    TreeNode *node=(TreeNode*)malloc(sizeof(TreeNode)),*node1=(TreeNode*)malloc(sizeof(TreeNode)),*node2=(TreeNode*)malloc(sizeof(TreeNode)),*node3=(TreeNode*)malloc(sizeof(TreeNode));
    node3->left=NULL;
    node3->right=NULL;
    node3->val=55;
    node2->right=NULL;
    node2->left=NULL;
    node2->val=120;
    node1->left=NULL;
    node1->right=NULL;
    node1->val=30;
    node->left=NULL;
    node->right=NULL;
    node->val=0;
    
    string s="";
    Codec obj1,obj2;
    s=obj1.serialize(node);
    TreeNode* n=obj2.deserialize(s);
    string s2=obj2.serialize(n);
    for(int i=0;i<s.length();i++)
        {
        cout<<s[i];
        }
    cout<<endl;
    for(int i=0;i<s.length();i++)
        {
        cout<<s[i];
        }
    cout<<endl;
    display(n);
    return 0;
    }
// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;