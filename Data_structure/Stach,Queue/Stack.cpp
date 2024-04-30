#include<iostream>
#include<conio.h>
using namespace std;
class Stack
    {
        public:
        Stack()
            {
                max=5;
                rear=-1;
            }
        void push(int n)
            {
                if(rear>=max-1)
                    {
                        cout<<"Stack Overflown!";
                    }
                else
                    {
                        rear++;
                        stack[rear]=n;
                        cout<<"Element is pushed";
                    }
            }
        void pop()
            {
                if(rear==-1)
                    {
                        cout<<"Empty Stack!";
                    }
                else    
                    {
                        rear=rear-1;
                        cout<<"Element is poped";
                    }
            }
        void display()
            {
                if(rear==-1)
                    {
                        cout<<"Empty Stack!";
                    }
                else    
                    {
                        for(int i=0;i<=rear;i++)
                            {
                                cout<<stack[i]<<" ";
                            }
                    }
            }
        int search(int n)
            {
                int f=-1;
                if(rear==-1)
                    {
                        cout<<"Empty Stack!";
                    }
                else
                    {
                        for(int i=0;i<=rear;i++)
                            {
                                if(stack[i]==n)
                                    {
                                        f=i;
                                        break;
                                    }
                            }
                    }
            return f;
            }
        void modify(int n)
            {
                int f;
                if(rear==-1)
                    {
                        cout<<"Empty Stack!";
                    }
                else    
                    {
                        f=search(n);
                        if(f==-1)
                            {
                                cout<<"Element not found!";
                            }
                        else    
                            {
                                int k;
                                cout<<"Enter new element=";
                                cin>>k;
                                stack[f]=k;
                                cout<<"Modified Stack=";
                                display();
                            }
                    }           
            }
        void check()
            {
                if(rear==-1)
                    {
                        cout<<"Empty Stack!";
                    }    
                else if(rear>=max-1)
                    {
                        cout<<"Stack Overflown!";
                    }
                else    
                    {
                        cout<<"Total elemnets present="<<rear+1;
                        cout<<"\nEmpty slots="<<max-rear-1;
                    }
            }
        void terminate()
            {
                rear=-1;
                cout<<"Stack terminated";
            }
        private:
        int max,stack[5],rear;
    };
int main()
    {
        Stack s;
        int i=0,n;
        while(i!=8)
            {
                system("cls");
                cout<<"\tSTACK";
                cout<<"\n1.Push";
                cout<<"\n2.Pop";
                cout<<"\n3.Display";
                cout<<"\n4.Search";
                cout<<"\n5.Modify";
                cout<<"\n6.Check";
                cout<<"\n7.Terminate";
                cout<<"\n8.Exit";
                cout<<"\n  Enter your choice=";                
                cin>>i;
                switch(i)
                    {
                        case 1:
                            {
                                cout<<"Enter new element=";
                                cin>>n;
                                s.push(n);
                                getch();
                                break;
                            }
                        case 2:
                            {
                                s.pop();
                                getch();
                                break;
                            }
                        case 3:
                            {
                                s.display();
                                getch();
                                break;
                            }
                        case 4:
                            {
                                int k;
                                cout<<"Enter element to search=";
                                cin>>n;
                                k=s.search(n);
                                if(k==-1)
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
                                cout<<"Enter element to modify=";
                                cin>>n;
                                s.modify(n);
                                getch();
                                break;
                            }
                        case 6:
                            {
                                s.check();
                                getch();
                                break;
                            }
                        case 7:
                            {
                                s.terminate();
                                getch();
                                break;
                            }
                        case 8:
                            {
                                cout<<"Quiting!!!";
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
    getch();
    return 0;
    }