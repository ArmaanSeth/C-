#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
struct node
    {
        string data;
        struct node* next;
    };
class hash_table
    {
        public:
        hash_table()
            {
                size=5;
                for(int i=0;i<5;i++)
                    {
                        hash[i]=NULL;
                    }
            }
        int function(string key)
            {
                int k=key.size();
                return (k%5);
            }
        void insertion(string key)
            {
                int value=function(key);
                if(hash[value]==NULL)
                    {
                        struct node* ob=new node;
                        ob->data=key;
                        ob->next=NULL;
                        hash[value]=ob;
                    }
                else 
                    {
                        node* ob=new node;
                        ob->data=key;
                        ob->next=NULL;
                        node* temp=new node;
                        temp=hash[value];
                        while(temp->next!=NULL)
                            {
                                temp=temp->next;
                            }
                        temp->next=ob;
                    }
            }
        int find(string key)
            {
                int i,j=0;
                for(i=0;i<5;i++)
                    {
                        if(hash[i]!=NULL)
                            {
                                struct node* temp=new node;
                                while(temp->next!=NULL)
                                    {
                                        if(temp->data==key)
                                            {
                                                j=1;
                                                break;
                                            }
                                        temp=temp->next;
                                    }
                                if(j==0)
                                    {
                                        if(temp->data==key)
                                            {
                                                j=1;
                                            }
                                    }
                            }
                    }
                return j;
            }
        void display()
            {
                int i=0;
                for(i=0;i<5;i++)
                    {
                         cout<<endl;
                        node* temp=new node;
                        temp=hash[i];
                        if(temp==NULL)
                            {
                                cout<<"NULL";
                            }
                        else
                            {
                                if(temp->next==NULL)
                                    {
                                        cout<<temp->data;
                                    }
                                else    
                                    {    
                                        while(temp->next!=NULL)
                                            {
                                                cout<<temp->data<<" ";
                                                temp=temp->next;
                                            }
                                        cout<<temp->data;
                                    }                            
                            }
                       
                    }
            }
        private:
        int size;
        struct node *hash[5];
    };
int main()
    {
    system("cls");
    hash_table h;
    int i=0;
    string n;
	while(i!=4)
		{
		system("cls");
		cout<<"1.Add Element\n";
        cout<<"2.Value\n";
		cout<<"3.Display\n";
        cout<<"4.Find\n";
		cout<<"4.Exit\n";
		cout<<"\nEnter your choice:";
		cin>>i;
		switch(i)
			{
			case 1:
				{
				cout<<"Enter key=";
				cin>>n;
				h.insertion(n);
                h.display();
                getch();
				break;
				}
            case 2:
                {
                cout<<"Enter Key=";
                cin>>n;
                int k=h.function(n);
                cout<<"\nValue="<<k;
                break;
                }
			case 3:
				{
				h.display();
                getch();
				break;
				}
            case 4:
                {
                cout<<"Enter key to find=";
                cin>>n;
                int k=h.find(n);
                if(k==0)
                    {
                        cout<<"Not Found";
                    }
                else    
                    {
                        cout<<"Found";
                    }
                getch();
                break;
                }
			case 5:
				{
				cout<<"Quiting\n";
				break;
				}
            default:
                {
                cout<<"Wrong choice";
                break;
                }
			}
		}
	getch();
    return 0;
    }
