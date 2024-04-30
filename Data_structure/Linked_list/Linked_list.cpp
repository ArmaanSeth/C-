#include <iostream>
#include<conio.h>
#include<stdlib.h>
#include <cstdlib>
using namespace std;
struct node
	{
	int data;
	struct node *next;
	};
struct node *head=NULL;
void append(int);
void insertbeg(int);
void del(int);
void search(int);
int modify(int);
void display();

int main()
	{
	int i=0,n;
	while(i!=7)
		{
	//	clrscr();
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
				break;
				}
			case 2:
				{
				cout<<"Enter element to insert at thee begining=";
				cin>>n;
				insertbeg(n);
				break;
				}
			case 3:
				{
				cout<<"Enter element to delete=";
				cin>>n;
				del(n);
				break;
				}
			case 4:
				{
				cout<<"Enter element to search=";
				cin>>n;
				search(n);
				break;
				}
			case 5:
				{
				int k;
				cout<<"Enter element to modify=";
				cin>>k;
				k=modify(n);
				if(k==0)
					{
					cout<<"Element not found";
					}
				break;
				}
			case 6:
				{
				display();
				break;
				}
			default:
				{
				cout<<"Quiting\n";
				getch();
				break;
				}
			}
		}
	return 0;
	getch();
	}
void append(int n)
	{
	struct node *ob=(struct node*)malloc(sizeof(struct node));
	ob->data=n;
	ob->next=NULL;
	if(head==NULL)
		{
		head=ob;
		}
	else
		{
		struct node *temp;
		temp=head;
		while(temp->next!=NULL)
			{
			temp=temp->next;
			}
		temp->next=ob;

		}
	}
void insertbeg(int n)
	{
	struct node *ob=(struct node*)malloc(sizeof(struct node));
	ob->data=n;
	if(head==NULL)
		{
		head=ob;
		ob->next=NULL;
		}
	else
		{
		ob->next=head;
		head=ob;
		}
	}
void search( int n)
	{
	struct node *temp;
	int k=0;
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
	if(k==1)
		{
		cout<<"Found";
		}
	else
		{
		cout<<"Not Found";
		}
	getch();
	}
void del(int n)
	{
	struct node *temp;
	struct node *ob;
	temp=head;
	while(temp!=NULL)
		{
		if(temp->data==n)
			{
			if(temp==head)
				{
				head=head->next;
				break;
				}
			else
				{
				ob->next=temp->next;
				break;
				}
			cout<<"Element Deleted";
			}
		ob=temp;
		temp=temp->next;
		}
	}
int modify(int n)
	{
	int k,i=0;
	struct node *temp;
	temp=head;
	while(temp!=NULL)
		{
		if(temp->data==n)
			{
			i=1;
			cout<<"Enter new element";
			cin>>k;
			temp->data=k;
			break;
			}
		temp=temp->next;
		}
	return i;
	}
void display()
	{
	struct node*temp;
	temp=head;
	while(temp!=NULL)
		{
		cout<<temp->data<<"  ";
		temp=temp->next;
		}
	getch();
	}