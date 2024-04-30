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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
    if(head==NULL || right==left)
        {
        return head;
        }
    int i=1;
    ListNode *temp1=head,*temp2=NULL,*temp3=NULL;
    while(i<left-1)
        {
        temp1=temp1->next;
        i++;
        }
    temp2=temp1;
    while(i<right)
        {
        temp2=temp2->next;
        i++;
        }
    if(left==1)
        {
        temp3=temp2->next;
        temp2->next=NULL;
        ListNode *curr=head,*prev=temp3;
        while(head!=NULL)
            {
            curr=head;
            head=head->next;
            curr->next=prev;
            prev=curr;
            }
        return prev;
        }
    temp3=temp1->next;
    temp1->next=temp2->next;
    temp2->next=NULL;
    ListNode *curr=temp3,*prev=temp1->next;
    while(temp3!=NULL)
        {
        curr=temp3;
        temp3=temp3->next;
        curr->next=prev;
        prev=curr;
        }
    temp1->next=prev;
    return head;
    }
};
int main()
    {
    system("cls");
    Solution obj;
    ListNode *head=new ListNode,*a=new ListNode,*b=new ListNode,*c=new ListNode,*d=new ListNode,*e=new ListNode;
    e->next=NULL;
    e->val=2;
    d->next=NULL;
    d->val=5;
    c->next=d;
    c->val=4;
    b->next=NULL;
    b->val=3;
    a->next=b;
    a->val=2;
    head->next=a;
    head->val=1;
    head=obj.reverseBetween(head,1,2);
    while(head!=NULL)
        {
        cout<<head->val<<" ";
        head=head->next;    
        }
    return 0;
    }