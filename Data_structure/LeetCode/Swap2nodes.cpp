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
    ListNode *temp1=head,*temp2=NULL;
    while(i<left-1)
        {
        temp1=temp1->next;
        i++;
        }
    temp2=temp1;
    while(i<right-1)
        {
        temp2=temp2->next;
        i++;
        }
    if(temp1==NULL || temp1->next==NULL || temp2==NULL || temp2->next==NULL)
        {
        return head;
        }
    if(left==1)
        {
        if(right==left+1)
            {
            head=head->next;
            temp1->next=head->next;
            head->next=temp1;
            }
        else
            {
            ListNode* temp3=temp2->next,*temp4=temp1->next;
            temp2->next=temp2->next->next;
            head=head->next;
            temp1->next=temp2->next;
            temp2->next=temp1;
            temp3->next=head;
            head=temp3;
            }
        }
    else
        {
        if(temp1->next==temp2)
            {
            ListNode* temp3=temp2->next;
            temp2->next=temp2->next->next;
            temp3->next=temp2;
            temp1->next=temp3;
            }
        else
            {   
            ListNode* temp3=temp2->next,*temp4=temp1->next;
            temp2->next=temp2->next->next;
            temp1->next=temp1->next->next;
            temp4->next=temp2->next;
            temp2->next=temp4;
            temp3->next=temp1->next;
            temp1->next=temp3;
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
    e->next=NULL;
    e->val=2;
    d->next=NULL;
    d->val=5;
    c->next=NULL;
    c->val=4;
    b->next=c;
    b->val=3;
    a->next=b;
    a->val=2;
    head->next=a;
    head->val=1;
    head=obj.reverseBetween(head,1,4);
    while(head!=NULL)
        {
        cout<<head->val<<" ";
        head=head->next;    
        }
    return 0;
    }