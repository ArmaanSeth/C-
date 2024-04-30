#include<iostream>
#include<map>
#include<vector>
using namespace std;
struct node{
    int val;
    struct node* left,*right;
};
class Solution {
private:
    map<int,int> m;
public:
    int factorial(int n,map<int,int> &m){
        if(n==0 || n==1)
            return 1;
        if(m[n]!=0)
            return m[n];
        else{
            int k=factorial(n-1,m)*factorial(n-2,m);
            m[n]=k;
            return k;
        }    
    }
    int permutations(node* root){
        if(root==NULL)
            return 0;
        else if(root->right!=NULL && root->right->right==NULL && root->right->left==NULL && root->left!=NULL && root->left->right==NULL && root->left->left==NULL)
            return 2;
        else{
            int a=permutations(root->right),b=permutations(root->left);
            if(b>a){
                int temp=a;
                a=b;
                b=a;
            }
            int k=(a+1)*a+factorial(a+1,m)/(factorial(b,m)*factorial(a+1-b,m));
            return k;
        }
    }
    void insert(node* &root,int n){
        if(root==NULL){
            node* temp=new node;
            temp->val=n;
            temp->right=NULL;
            temp->left=NULL;
            root=temp;
        }   
        else{
            if(root->val>n){
                if(root->left==NULL){
                    node* temp=new node;
                    temp->val=n;
                    temp->right=NULL;
                    temp->left=NULL;
                    root->left=temp;
                }
                else    
                    insert(root->left,n);
            }
            else{
                if(root->right==NULL){
                    node* temp=new node;
                    temp->val=n;
                    temp->right=NULL;
                    temp->left=NULL;
                    root->right=temp;
                }
                else
                    insert(root->right,n);
            }
        }
    }
    int numOfWays(vector<int>& nums) {
        node* root=NULL;
        for(int i=0;i<nums.size();i++) 
            insert(root,nums[i]);

        return permutations(root)-1;
    }
};
int main(){
    system("cls");
    vector<int> a={2,1,3};
    Solution obj;
    int ans=obj.numOfWays(a);
    cout<<"Ans="<<ans<<endl;
    return 0;
}