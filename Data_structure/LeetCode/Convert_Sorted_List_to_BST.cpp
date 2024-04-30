#include<iostream> 
using namespace std;
struct ListNode
    {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
struct TreeNode 
    {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
class Solution 
    {   
    public:
    ListNode* reverse(ListNode* head)
        {
        ListNode *prev=NULL,*curr=NULL;
        while(head!=NULL)
            {
            curr=head;
            head=head->next;
            curr->next=prev;
            prev=curr;
            }
        return prev;
        }
    TreeNode* sortedListToBST(ListNode* head) 
        {
        TreeNode *T_head=new TreeNode;
        if(head==NULL)
            {
            return NULL;
            }
        else if(head->next==NULL)
            {
            T_head->val=head->val;
            T_head->left=NULL;
            T_head->right=NULL;    
            return T_head;
            }
        else if(head->next->next==NULL)
            {
            TreeNode *l=new TreeNode;
            T_head->val=(head->next)->val;
            l->val=head->val;
            l->left=NULL;
            l->right=NULL;
            T_head->left=l;
            T_head->right=NULL;
            return T_head;
            }
        bool flag=false;
        ListNode *temp1=head,*temp2=head,*temp3=NULL,*temp4=head;
        while(temp2!=NULL && temp2->next!=NULL)
            {
            if(flag==true)
                {
                temp4=temp4->next;
                }
            flag=true;
            if(temp2->next->next==NULL)
                {
                break;
                }
            temp1=temp1->next;
            temp2=temp2->next->next;
            }
        if(temp2->next==NULL)
            {
            T_head->val=(temp4->next)->val;
            temp3=(temp4->next)->next;
            temp4->next=NULL;
            }
        else
            {
            temp3=(temp1->next)->next;
            T_head->val=(temp1->next)->val;
            temp1->next=NULL;
            }
        T_head->left=sortedListToBST(head);
        T_head->right=sortedListToBST(temp3);
        return T_head;
        }
    };
int main()
    {
    system("cls");
    Solution obj;
    TreeNode *treehead=NULL;
    ListNode *head=new ListNode,*a=new ListNode,*b=new ListNode,*c=new ListNode,*d=new ListNode,*e=new ListNode;
    e->next=NULL;
    e->val=2;
    d->next=NULL;
    d->val=5;
    c->next=d;
    c->val=4;
    b->next=c;
    b->val=3;
    a->next=b;
    a->val=2;
    head->next=a;
    head->val=1;
    treehead=obj.sortedListToBST(head);
    return 0;
    }