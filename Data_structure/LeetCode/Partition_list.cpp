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
    ListNode *temp=head->next,*temp2=head;
    while(temp->next!=NULL)
        {
        if((temp->val)<x)
            {
            ListNode* temp3=NULL;
            temp3=temp;
            if((head->val)>(temp->val))
                {
                temp2=temp;
                temp=(temp2->next)->next;
                temp3->next=head;
                head=temp3;
                continue;
                }
            ListNode *move=new ListNode;
            move=head;
            while((move->next!=NULL) && ((move->next)->val)<(temp->val))
                {
                move=move->next;
                }
            temp=(temp2->next)->next;
            temp2=(temp2->next)->next;
            temp3->next=move->next;
            move->next=temp3;
            }
        else
            {
            temp2=temp;
            temp=temp->next;
            }
        }
    if((temp->val)<x)
        {
        ListNode* move=head,*temp3=temp;
        while(move->next!=NULL && ((move->next)->val)<(temp->val))
            {
            move=move->next;
            }
        temp2->next=NULL;
        temp=temp2->next;
        temp3->next=move->next;
        move->next=temp3;    
        }
    return head;
    }
};
int main()
    {
    system("cls");
    Solution obj;
    ListNode *head,*a,*b,*c,*d,*e;
    head->next=a;
    head->val=1;
    a->next=b;
    a->val=4;
    b->next=c;
    b->val=3;
    c->next=d;
    c->val=2;
    d->next=e;
    d->val=5;
    e->next=NULL;
    e->val=2;
    head=obj.partition(head,3);
    while(head!=NULL)
        {
        cout<<head->val<<" ";
        head=head->next;    
        }
    return 0;
    }