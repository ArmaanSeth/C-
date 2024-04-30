#include<iostream>
#include<conio.h>
using namespace std;
class Queue
    {
        public:
        Queue()
            {
                max=5;
                rear=-1;
                front=-1;
            }
        void push()
            {
                if(rear==max-1)
                    {
                        cout<<"Queue Overflown!";
                    }
                else
                    {
                    int n;
                    cout<<"Enter new element=";
                    cin>>n;
                    if(front==-1)
                        {
                            front++;
                            rear++;
                            queue[front]=n;
                        }
                    else  
                        {
                            rear++;
                            queue[rear]=n;
                            cout<<"Element is pushed";
                        }
                    cout<<"Element is pushed";
                    }
            }
        void pop()
            {
                if(front==rear)
                    {
                        cout<<"Empty Queue!";
                    }
                else    
                    {
                        for(int i=0;i<rear;i++)
                            {
                                queue[i]=queue[i+1];
                            }
                        cout<<"Element is pooped";
                        rear--;
                    }
            }
        void display()
            {
                if(front==rear)
                    {
                        cout<<"Empty Queue!";
                    }
                else    
                    {
                        for(int i=0;i<=rear;i++)
                            {
                                cout<<queue[i]<<" ";
                            }
                    }
            }
        int search(int n)
            {
                int f=-1;
                if(front==rear)
                    {
                        cout<<"Empty Queue!";
                    }
                else
                    {
                        for(int i=0;i<=rear;i++)
                            {
                                if(queue[i]==n)
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
                if(front==rear)
                    {
                        cout<<"Empty Queue!";
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
                                queue[f]=k;
                                cout<<"Modified Queue=";
                                display();
                            }
                    }           
            }
        void check()
            {
                if(front==rear)
                    {
                        cout<<"Empty Queue!";
                    }    
                else if(rear==max-1)
                    {
                        cout<<"Queue Overflown!";
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
                front=-1;
                cout<<"Queue terminated";
            }
        private:
        int max,queue[5],rear,front;
    };
int main()
    {
        Queue q;
        int n,i;
        while(i!=8)
            {
                system("cls");
                cout<<"\tQUEUE";
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
                                q.push();
                                getch();
                                break;
                            }
                        case 2:
                            {
                                q.pop();
                                getch();
                                break;
                            }
                        case 3:
                            {
                                q.display();
                                getch();
                                break;
                            }
                        case 4:
                            {
                                int k;
                                cout<<"Enter element to search=";
                                cin>>n;
                                k=q.search(n);
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
                                q.modify(n);
                                getch();
                                break;
                            }
                        case 6:
                            {
                                q.check();
                                getch();
                                break;
                            }
                        case 7:
                            {
                                q.terminate();
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
    