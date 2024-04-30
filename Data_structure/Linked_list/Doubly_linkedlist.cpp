#include<iostream>
#include<conio.h>
using namespace std;
struct node
    {
        int data;
        struct node *next;
        struct node *back;
    }*head=NULL,*tail=NULL;

int append(int n)
    {
        struct node *ob=new node;
        ob->data=n;
        if(head==NULL && tail==NULL)
            {
                head=ob;
				head->next=tail;
				head->back=NULL;
				tail=NULL;
            }
		else if(tail==NULL && head!=NULL)
			{
				tail=ob;
				tail->back=head;
				head->next=tail;
				tail->next=NULL;
			}
        else    
            {
                tail->next=ob;
                ob->back=tail;
				ob->next=NULL;
				tail=ob;
            }
		cout<<"Element Appended";
    return 0;
    }
int insert(int n)
    {
        struct node* ob=new node;
        ob->data=n;
        if(head==NULL && tail==NULL)
            {
                head=ob;
                head->next=tail;
                head->back=NULL;
				tail=NULL;
            }
		else if(head!=NULL && tail==NULL)
			{
				tail=head;
				head=ob;
				head->back=NULL;
				head->next=tail;
				tail->back=head;
				tail->next=NULL;
			}
        else
            {
                ob->next=head;
                head->back=ob;
                head=ob;
            }
		cout<<"Element Inserted";
		return 0;
    }
struct node *search(int n)
    {
		if(head==NULL)
			{
				return 0;
			}
        int k=-1;
        struct node *temp=new node;
        temp=head;
        while(temp!=NULL)
            {
                if(temp->data==n)
                    {
                        k=1;
                        break;
                    }
				temp=temp->next;
            }
		if(k==-1)
			{
				temp==NULL;
			}
        return temp;
    }
int del(int n)
    {
		struct node *ob=search(n),*temp=new node;
		if(ob==NULL)
			{
				cout<<"Element not present!!!";
			}
		else if(ob==head)
			{
				if(ob->next==tail)
					{
						if(tail==NULL)
							{
								head=NULL;
								tail=NULL;
							}
						else
							{
								head=tail;
								tail=NULL;
							/*	head->next=tail;
								head->back=NULL;
								tail->back=head;*/
							}
					}
				else
					{
						head=head->next;
						head->back=NULL;
					}
				cout<<"Element Deleted";
			}
		else if(ob==tail)
			{
				if(ob->back==head)
					{
						tail=NULL;
						head->next=tail;
					}
				else
					{
						tail=tail->back;
						tail->next=NULL;
					}
				cout<<"Element deleted";
			}
		else	
			{
				(ob->back)->next=(ob->next);
				(ob->next)->back=(ob->back);
				cout<<"Element deleted";
			}
		return 0;
    }
int modify(int n)
	{
		struct node *ob=search(n),*temp=new node;
		if(ob==NULL)
			{
				cout<<"Element not found";
			}
		else if(ob==0)
			{
				cout<<"Empty List!!!";
			}
		else 
			{
				int k;
				cout<<"Enter new element=";
				cin>>n;
				ob->data=n;
				cout<<"Element Modified";
			}
		return 0;
	}
int display()
	{
		struct node *temp=new node;
		temp=head;
		if(temp==NULL)
			{
				cout<<"Empty List!!!";
				return 0;
			}
		while(temp!=NULL)
			{
				cout<<temp->data<<" ";
				temp=temp->next;
			}
		if(head==NULL)
			{
				cout<<"\nHead=NULL";
			}
		else
			{
				cout<<"\nHead="<<head->data;
			}
		if(tail==NULL)
			{
				cout<<"\nTail=NULL";
			}
		else
			{
				cout<<"\nTail="<<tail->data;
			}
		return 0;
	}
int main()
	{
	int i=0,n;
	while(i!=7)
		{
		system("cls");
		cout<<"1.Append\n";
		cout<<"2.Insert in the Begining\n";
		cout<<"3.Delete\n";
		cout<<"4.Search\n";
		cout<<"5.Modify\n";
		cout<<"6.Display\n";
		cout<<"7.Exit\n";
		cout<<"\nEnter your choice:";
		cin>>i;
		switch(i)
			{
			case 1:
				{
				cout<<"Enter element to append=";
				cin>>n;
				append(n);
				getch();
				break;
				}
			case 2:
				{
				cout<<"Enter element to insert=";
				cin>>n;
				insert(n);
				getch();
				break;
				}
			case 3:
				{
				cout<<"Enter element to delete=";
				cin>>n;
				del(n);
				getch();
				break;
				}
			case 4:
				{
				cout<<"Enter element to search=";
				cin>>n;
				struct node *temp=new node;
				temp=search(n);
				if(temp==NULL)
					{
						cout<<"Element not Found";
					}
				else if(temp==0)
					{
				cout<<"Empty List!!!";
					}
				else
					{
						cout<<"Element Found";
					}
				getch();
				break;
				}
			case 5:
				{
				int i;
				cout<<"Enter element to modify=";
				cin>>n;
				modify(n);
			/*	if(i==0)
					{
					cout<<"Element not found";
					}*/
				getch();
				break;
				}
			case 6:
				{
				display();
				getch();
				break;
				}
			case 7:
				{
				cout<<"Quiting\n";
				getch();
				break;
				}
			default :
				{
					cout<<"Wrong Choice!!!";
					getch();
					break;
				}
			}
		}
	return 0;
	getch();
	}