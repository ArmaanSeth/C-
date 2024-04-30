#include<iostream>
#include<conio.h>
using namespace std;
class Fenwik_tree
    {
    public:
    Fenwik_tree()
        {
            size=13;
        }
    Fenwik_tree(int n)
        {
            size=n;
            int i=0;
           /* for(i=0;i<size;i++)
                {
                    arr[i]=0;
                    tree[i]=0;
                }*/
        }
    void add()
        {
            cout<<"size="<<size;
            int i=0;
            while(i!=size)
                {
                cin>>arr[i];
                tree[i]=arr[i];
                cout<<"I="<<i<<" arr="<<arr[i]<<"  tree="<<tree[i]<<endl;
                i++;
                }
        }
    int find(int n)
        {
            int i=0;
            while(i!=size)
                {
                    if(arr[i]==n)
                        {
                            break;
                        }
                    i++;
                }
            return i;
        }
    int LSB(int n)
        {
            return n&-n;
        }
    void maketree()
        {
            int i=1,j,lsb;
            while(i<size)
                {
                    lsb=LSB(i);
                    j=i+lsb;
                    if(j<size)
                        {
                        tree[j]=tree[j]+tree[i];
                        }
                    i++;
                }
        }
    int tree_value(int i)
        {
            return tree[i];
        }
    int sum(int i)
        {
            int s=0,lsb;
            while(i!=0)
                {
                    lsb=LSB(i);
                    s+=tree[i];
                    i=i-lsb;
                    
                }
            return s;
        }
    void update(int n,int i)
        {
            int k=arr[i],lsb;
            arr[i]=n;
            k=k-n;
            while(i<size)
                {
                    lsb=LSB(i);
                    tree[i]=tree[i]+k;
                    i=i+lsb;
                }
        }
    void display()
        {
            int i=0;
            while(i<size)
                {
                    cout<<tree[i]<<endl;
                    i++;
                }   
        }
    private:
        int size,*arr=new int[size], *tree=new int[size];
    };
int main()
    {
        system("cls");
        int i=0,n;
        Fenwik_tree t(6);
        while(i!=5)
            {
                system("cls");
                cout<<"\n1.Enter Elements";
                cout<<"\n2.Modify Elements";
                cout<<"\n3.Display";
                cout<<"\n4.Sum";
                cout<<"\n5.Range Sum";
                cout<<"\n6.Exit";
                cout<<"\nEnter your choice=";
                cin>>i;
                switch(i)
                    {
                        case 1:
                            {
                                t.add();
                                t.maketree();
                                break;
                            }
                        case 2:
                            {
                                int j,n,a;
                                cout<<"Enter element to modify=";
                                cin>>a;
                                j=t.find(a);
                                cout<<"Enter new element";
                                cin>>a;
                                t.update(a,j);
                                break;
                            }
                        case 3:
                            {
                                t.display();
                                getch();
                                break;
                            }
                        case 4:
                            {
                                int j;
                                cout<<"Enter sum range from 0=";
                                cin>>j;
                                j=t.sum(j);
                                cout<<"Sum="<<j;
                                getch();
                                break;
                            }
                        case 5:
                            {
                                int m,n,k;
                                cout<<"Enter range of type [m,n]=";
                                cin>>m>>n;
                                m=t.sum(m-1);
                                n=t.sum(n);
                                cout<<"Sum="<<n-m;
                                getch();
                                break;
                            }
                        case 6:
                            {
                                cout<<"Quitting!!!";
                                getch();
                                break;
                            }
                        default:
                            {
                                cout<<"Wrong Choice!!!";
                                getch();
                                break;
                            }
                    }
            }
        
        return 0;
    }