#include<iostream>
#include<conio.h>
using namespace std;
class Circular_Queue
    {
        public:
        Circular_Queue()
            {
                max=5;
                rear=-1;
                front=-1;
            }
        void push()
            {
                if((rear+1)==front || (rear-front)==max-1)
                    {                                                                                                                                                                                                                                                                                                                     
                        cout<<"Queue Overflown!";
                    }
                else  
                    {
                        int n;
                        cout<<"Enter new element=";
                        cin>>n;
                        if(rear==-1)
                            {
                                front=0;
                                rear=0;
                                queue[front]=n;
                            }
                        else if(rear+1==max)
                            {
                                rear=0;
                                queue[rear]=n;
                            }
                        else
                            {
                                rear++;
                                queue[rear]=n;
                            }
                        cout<<"Element is pushed";
                    }
            }
        void pop()
            {
                if(front==-1)
                    {
                        cout<<"Empty Queue!";
                    }
                else    
                    {
                        if(front==rear)
                            {
                                front=-1;
                                rear=-1;
                            }
                        else if(front==max-1)
                            {
                                front=0;
                            }
                        else
                            {
                                front++;
                            }
                        cout<<"Element is pooped";
                    }
            }
        void display()
            {
                if(front==-1)
                    {
                        cout<<"Empty Queue!";
                    }
                else if(front<rear)    
                    {
                        for(int i=front;i<=rear;i++)
                            {
                                cout<<queue[i]<<" ";
                            }
                    }
                else
                    {
                        int i;
                        for(i=front;i<max;i++)
                            {
                                cout<<queue[i]<<" ";
                            }
                        for(i=0;i<=rear;i++)
                            {
                                cout<<queue[i]<<" ";
                            }
                    }
            }
        int search(int n)
            {
                int f=-1;
                if(front==-1)
                    {
                        cout<<"Empty Queue!";
                    }
                else if(front<rear)
                    {
                        for(int i=front;i<=rear;i++)
                            {
                                if(queue[i]==n)
                                    {
                                        f=i;
                                        break;
                                    }
                            }
                    }
                else
                    {
                        int i;
                        for(i=front;i<max;i++)
                            {
                                if(queue[i]==n)
                                    {
                                        f=i;
                                        break;
                                    }    
                            }
                        for(i=0;i<=rear;i++)
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
                if(front==-1)
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
                if(front==-1)
                    {
                        cout<<"Empty Queue!";
                    }    
                else if((rear+1)==front || (rear-front)==max-1)
                    {
                        cout<<"Queue Overflown!";
                    }
                else    
                    {
                        if(front<rear)
                            {
                            cout<<"Total elemnets present="<<rear-front+1;
                            cout<<"\nEmpty slots="<<max-rear+front-1;
                            }
                        else
                            {
                            cout<<"Total elemnets present="<<(max-front)+(rear+1);
                            cout<<"\nEmpty slots="<<max+front-rear-1;
                            }
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
        Circular_Queue q;
        int n,i;
        while(i!=8)
            {
                system("cls");
                cout<<"\tCIRCULAR QUEUE";
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
    