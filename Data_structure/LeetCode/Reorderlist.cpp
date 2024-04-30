#include<iostream>
using namespace std;
struct ListNode
    {
    int val;
    struct ListNode *next;
    };
struct ListNode *head=NULL;
void addnode(int n)
    {
    ListNode *temp=new ListNode,*ob=new ListNode;
    ob->next=NULL;
    ob->val=n;
    if(head==NULL)
        {
        head=ob;
        return;
        }
    temp=head;
    while(temp->next!=NULL)
        {
        temp=temp->next;
        }
    temp->next=ob;
    }
class Solution 
    {
    public:
    ListNode* reverse(ListNode* head)
        {
        ListNode *cur=NULL,*pre=NULL,*temp=head;
        while(temp!=NULL)
            {
            cur=temp;
            temp=temp->next;
            cur->next=pre;
            pre=cur;
            }
        return pre;
        }
    ListNode* rec(ListNode* head,ListNode* m)
        {
        if(m==NULL)//|| (head==NULL && m->next!=NULL))
            {
            return m;
            }    
        if(head->next==NULL)
            {
            return m;
            }
        ListNode *temp;
        temp=head->next;
        head->next=m;
        m=m->next;
        (head->next)->next=rec(temp,m);
        return head;
        }
    ListNode* reorderList(ListNode* head) 
        {
        ListNode *m=head,*temp=head;
        while(temp!=NULL && temp->next!=NULL)
            {
            m=m->next;
            temp=(temp->next)->next;
            }
        m=reverse(m);
        head=rec(head,m);        
        return head;
        }
    };
int main()
    {
    system("cls");
    addnode(1);
    addnode(2);
    addnode(3);
    addnode(4);
    addnode(5);
    Solution obj;
    head=obj.reorderList(head);
    while(head!=NULL)
        {
        cout<<head->val<<" ";
        head=head->next;
        }
    return 0;
    }
