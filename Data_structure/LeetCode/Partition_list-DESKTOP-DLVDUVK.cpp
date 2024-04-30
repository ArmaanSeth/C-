#include<iostream>
using namespace std;
//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 class Solution {
public:
    ListNode* partition(ListNode* head, int x) 
    {
    if(head==NULL)
        {
        return head;
        }
    ListNode *temp=head,*temp2=new ListNode;
    temp2=head;
    if(head->val<x)
        {
        while(temp2->next !=NULL)
            {
            if((temp2->next)->val>=x)
                {
                break;
                }
            temp2=temp2->next;
            }
        if(temp2->next==NULL)
            {
            return head;
            }
        temp=temp2;
        while(temp!=NULL && temp->next!=NULL)
            {
            if((temp->next)->val<x)
                {
                ListNode* temp3=temp->next;
                temp->next=(temp->next)->next;
                temp3->next=temp2->next;
                temp2->next=temp3;
                temp2=temp2->next;
                }
            else
                {
                temp=temp->next;
                }
            }       
        }
    else
        {
        bool first=true;
        while(temp!=NULL && temp->next!=NULL)
            {
            if((temp->next)->val<x)
                {
                ListNode* temp3=temp->next;
                if(first==true)
                    {
                /*    if((temp->next)->next==NULL)
                        temp->next=NULL;
                    else*/
                    temp->next=(temp->next)->next;
                    temp3->next=head;
                    head=temp3;
                    temp2=head;
                    first=false;
                    continue;
                    }
                temp->next=(temp->next)->next;
                temp3->next=temp2->next;
                temp2->next=temp3;
                temp2=temp2->next;
                }
            else
                {
                temp=temp->next;
                }
            }
        }
    return head;
    }
};
int main()
    {
    system("cls");
    Solution obj;
    ListNode *head=new ListNode,*a=new ListNode,*b=new ListNode,*c=new ListNode,*d=new ListNode,*e=new ListNode;
   /* e->next=NULL;
    e->val=2;
    d->next=e;
    d->val=5;
    c->next=d;
    c->val=2;*/
    b->next=NULL;
    b->val=2;
    a->next=b;
    a->val=1;
    head->next=a;
    head->val=3;
    head=obj.partition(head,3);
    while(head!=NULL)
        {
        cout<<head->val<<" ";
        head=head->next;    
        }
    return 0;
    }