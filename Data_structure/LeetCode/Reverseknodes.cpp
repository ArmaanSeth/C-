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
    ListNode* rev(ListNode* head,ListNode* cur,int k,int i)
        {
        if(head==NULL || len(head,k*i)==false)
            {
            return head;
            }
        int n=0;
        ListNode* temp=NULL,*pre=head,*add=NULL;
        while(n<(k*(i-1)-1))
            {
            if(n==0)
                add=head;
            add=add->next;
            n++;
            }
        n=0;
        while(n<(k*i))
            {
            pre=pre->next;
            n++;
            }
        n=0;
        while(cur!=NULL && n<k)
            {
            temp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=temp;
            n++;
            }
        if(add==NULL)
            {
            pre=rev(pre,cur,k,i+1);
            }
        else
            {
            add->next=pre;
            pre=head;
            pre=rev(pre,cur,k,i+1);
            }
        return pre;
        }
    bool len(ListNode* head,int k)
        {
        int l=0;
        while(head!=NULL)
            {
            l++;
            head=head->next;
            }
        if(k<=l)
            {
            return true;
            }
        return false;
        }
    ListNode* reverseKGroup(ListNode* head, int k) 
        {
        if(k<2)
            {
            return head;
            }
        return rev(head,head,k,1);
        }
    };
int main()
    {
    addnode(1);
    addnode(2);
    addnode(3);
    addnode(4);
    addnode(5);
    Solution obj;
    obj.reverseKGroup(head,2);
    return 0;
    }
