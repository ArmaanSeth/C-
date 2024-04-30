#include<iostream>
#include<conio.h>
using namespace std;
class dynamic_array
    {
        public:
        dynamic_array()
            {
                n=3;
                capacity=0;
            }
        void get()
            {
                cout<<"\nCapacity="<<capacity<<"\nsize="<<n;
            }
        int insert(int x)
            {
                if(capacity<n)
                    {
                        int i;
                        for(i=(capacity-1);i>=0;i--)
                            {
                                arr[i+1]=arr[i];
                            }
                        arr[0]=x;
                        capacity++;
                    }
                else    
                    {
                        n=n*2;
                        int i=0;
                        for(i=(capacity-1);i>=0;i--)
                            {
                                arr[i+1]=arr[i];
                            }
                        arr[0]=x;
                        capacity++;
                    }
                cout<<"Element Inserted";
                return 0;
            }
        int append(int x)
            {
                if(capacity<n)
                    {
                        arr[capacity]=x;
                        capacity++;
                    }
                else    
                    {
                        n=n*2;
                        arr[capacity]=x;
                        capacity++;
                    }
                cout<<"Element Appended";
            return 0;
            }
        int del(int x)
            {
                int pos=search(x);
                if(pos==-1)
                    {
                        cout<<"Element not found!!!";
                        return 0;
                    }
                for(int i=pos+1;i<capacity;i++)
                    {
                        arr[i-1]=arr[i];
                    }
                capacity--;
                cout<<"Element deleted";
                return 0;
            }
        int search(int x)
            {
                int i,pos=-1;
                for(i=0;i<capacity;i++)
                    {
                        if(arr[i]==x)
                            {
                                pos=i;
                                break;
                            }
                    }
                return pos;
            }
        int modify(int x)
            {
                int pos=search(x);
                if(pos==-1)
                    {
                        cout<<"Element not found!!!";
                        return 0;
                    }
                int c;
                cout<<"Enter new element=";
                cin>>c;
                arr[pos]=c;
                cout<<"Element Modified";
                return 0;
            }
        void display()
            {
                if(capacity==0)
                    {
                        cout<<"Array is empty!!!";
                    }
                for(int i=0;i<capacity;i++)
                    {
                        cout<<arr[i]<<" ";
                    }
            }
        void terminate()
            {
                cout<<"Array Terminated";
                capacity=0;
            }
        private:
        int n,capacity,*arr=new int[n];
    };
int main()
    {
        dynamic_array a;
        int i,n;
        while(i!=8)
            {
                system("cls");
                cout<<"\tDYNAMIC ARRAY";
                cout<<"\n1.Insert";
                cout<<"\n2.Append";
                cout<<"\n3.Delete";
                cout<<"\n4.Search";
                cout<<"\n5.Modify";
                cout<<"\n6.Display";
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
                                a.insert(n);
                                getch();
                                break;
                            }
                        case 2:
                            {
                                cout<<"Enter new element=";
                                cin>>n;
                                a.append(n);
                                getch();
                                break;
                            }
                        case 3:
                            {
                                cout<<"Enter element to delete=";
                                cin>>n;
                                a.del(n);
                                getch();
                                break;
                            }
                        case 4:
                            {
                                int k;
                                cout<<"Enter element to search=";
                                cin>>n;
                                k=a.search(n);
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
                                a.modify(n);
                                getch();
                                break;
                            }
                        case 6:
                            {
                                a.display();
                                a.get();
                                getch();
                                break;
                            }
                        case 7:
                            {
                                a.terminate();
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