//doesn't take more than 7 elements :error 
#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
class binaryheap
    {
        public:
        binaryheap()
            {
                heap_size=0;
                heap_capacity=0;
            }
        binaryheap(int n)
            {
                heap_capacity=n;
                heap_size=0;
            }
        int isempty()
            {
                if(heap_size==0)
                    {
                        return 0;
                    }
                return -1;
            }
        int parent(int i)
            {
                return (i-1)/2;
            }
        int lchild(int i)
            {
                if(2*i+1<heap_size)
                    {
                        return (2*i+1);
                    }
                else
                    {
                        return -1;
                    }
            }
        int rchild(int i)
            {
                if(2*i+2<heap_size)
                    {
                        return (2*i+2);
                    }
                else    
                    {
                        return -1;
                    }
            }
        int schild(int i)
            {
                if(lchild(i)<heap_size && rchild(i)<heap_size)
                    {
                    if(arr[lchild(i)]<arr[rchild(i)])
                        {
                            return lchild(i);
                        }
                    else
                        {
                            return rchild(i);
                        }
                    }
                else if(lchild(i)<heap_size)
                    {
                    return lchild(i);
                    }
                else
                    {
                        return -1;
                    }
            }
        int swap(int i, int j)
            {
                int temp;
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                return 0;
            }
        int search(int n)
            {
                int i=0;
                for(i=0;i<heap_size;i++)
                    {
                        if(arr[i]==n)
                            {
                                return i;
                            }
                    }
                return -1;
            }
        int append(int n)
            {
                if(heap_size==heap_capacity)
                    {
                        cout<<"Heap Overflown";
                    }
                else
                    {
                        int i=heap_size;
                        arr[heap_size]=n;
                        heap_size++;
                        while(i!=0 && arr[parent(i)]>=arr[i])
                            {
                                swap(i,parent(i));
                                i=parent(i);
                            }
                        cout<<"Element added";
                    }
                return 0;
            }
        int modify(int n)
            {
                int i=1;
                i=isempty();
                if(i==0)
                    {
                        cout<<"Empty Heap";
                        return 0;
                    }
                i=search(n);
                if(i==-1)
                    {
                        cout<<"Element not present";
                    }
                else    
                    {
                        cout<<"Enter new element=";
                        cin>>n;
                        arr[i]=n;
                        while(i!=0 && arr[parent(i)]>=arr[i])
                            {
                                swap(i,parent(i));
                                i=parent(i);
                            }
                        cout<<"Element modified";
                    }
                return 0;
            }
        void poll()
            {
                if(heap_size==0)
                    {
                        cout<<"Empty Heap!!!";
                    }
                else
                    {
                        swap(0,heap_size-1);
                        heap_size--;
                        int j=schild(0),i=0;
                        while(i<heap_size && arr[i]>arr[j])
                            {
                                cout<<endl;
                                swap(i,j);
                                i=j;
                                j=schild(i);
                                
                            }
                        cout<<"\nElement polled";
                    }
            }
        int heapify(int n)
            {
                int small=smallest();
                int l=lchild(n);
                int r=rchild(n);
                if (arr[n]>arr[l] && arr[n]>arr[r] && l!=-1 && r!=-1)
                    {
                       swap(n,schild(n));
                    }
                else if(arr[n]>arr[l] && l!=-1)
                    {
                        swap(n,l);
                    }
                else if(arr[n]>arr[r] && r!=-1)
                    {
                        swap(n,r);
                    }
                if(r!=-1)
                    {
                        heapify(r);
                    }
                if(l!=-1)
                    {
                        heapify(l);
                    }
                return arr[0];
            }
        int smallest()
            {
                if(heap_size==0)
                    {
                        return -1;
                    }
                int m=0,small,i=0;
                small=arr[m];
                for(i=m;i<heap_size;i++)
                    {
                        if(small>arr[i])
                            {
                                small=arr[i];
                            }
                    }
                return small;
            }
        int del(int n)
            {
                int i;
                i=isempty();
                if(i==0)
                    {
                        cout<<"Empty heap!!!";
                        return 0;
                    }
                i=search(n);
                if(i==-1)
                    {
                        cout<<"Element not found!!!";
                    }
                else    
                    {
                        swap(arr[i],arr[heap_size-1]);
                        while(i!=0 && arr[parent(i)]>=arr[i])
                            {
                                swap(i,parent(i));
                                i=parent(i);
                            }
                        heap_size--;
                        cout<<"Element deleted";
                    }
                return 0;
            }
        void display()
            {
                int n=1,k=0;
                while(n<=heap_size)
                    {
                        n=n*2;
                        k++;
                    }
                k++;
                n=0;
                for(int i=0;i<k;i++)
                    {
                        cout<<"\t";
                        for(int j=i+1;j<k;j++)
                            {
                                cout<<" ";
                            }
                        for(int c=0;c<pow(2,i);c++)
                            {
                                if(n<heap_size)
                                    {
                                        cout<<arr[n]<<" ";
                                        n++;
                                    }
                                else    
                                    {
                                        break;
                                    }
                            }
                        cout<<"\n";
                    }
                //cout<<"capacity="<<heap_capacity;
                //cout<<"\nsize="<<heap_size;
            }
        
        void convert()
            {
                if(heap_size==0)
                    {
                        cout<<"Empty Heap";
                    }
                else 
                    {
                        int a[heap_size],i,k=0;
                        for(i=0;i<heap_size;i++)
                            {
                                a[i]=arr[i];
                            }
                        heap_size=0;
                        for(int j=0;j<i;j++)
                            {
                                k=heap_size;
                                arr[heap_size]=a[j];
                                heap_size++;
                                while(k!=0 && arr[parent(k)]<=arr[k])
                                    {
                                        swap(k,parent(k));
                                        k=parent(k);
                                    }
                            }
                    }
                cout<<"Converted to Max Heap\n";
                display();
            }
            
        private:
        int heap_size,heap_capacity,*arr=new int[heap_capacity];
    };
    int main()
        {
            int i=0,n=0,k=1;
            system("cls");
            cout<<"\tBINARY HEAP";
            cout<<"\n Enter heap capacity=";
            cin>>n;
            binaryheap h(n);
            while(i!=9)
                {
                    system("cls");
                    cout<<"\tBINARY HEAP";
                    cout<<"\n1.Append";
                    cout<<"\n2.Poll";
                    cout<<"\n3.Heapify";
                    cout<<"\n4.Search";
                    cout<<"\n5.Modify";
                    cout<<"\n6.Delete";
                    cout<<"\n7.Display";
                    cout<<"\n8.Convert min heap to max heap";
                    cout<<"\n9.Exit";
                    cout<<"\n  Enter your choice=";
                    cin>>i;
                    switch(i)
                        {
                            case 1:
                                {
                                    cout<<"Enter new element=";
                                    cin>>k;
                                    h.append(k);
                                    getch();
                                    break;
                                }
                            case 2:
                                {
                                    h.poll();
                                    getch();
                                    break;
                                }
                            case 3:
                                {
                                    k=h.smallest();
                                    if(k==-1)
                                        {
                                            cout<<"Empty Heap";
                                            break;
                                        }
                                    n=-1;
                                    while(n!=k)
                                        {
                                            n=h.heapify(0);
                                        }
                                    h.display();
                                    getch();
                                    break;
                                }
                            case 4:
                                {
                                    k=h.isempty();
                                    if(k==0)
                                        {
                                            cout<<"Empty Heap!!!";
                                            getch();
                                            break;
                                        }
                                    cout<<"Enter element to search=";
                                    cin>>k;
                                    k=h.search(k);
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
                                    k=h.isempty();
                                    if(k==0)
                                        {
                                            cout<<"Empty Heap!!!";
                                            getch();
                                            break;
                                        }
                                    cout<<"Enter element to modify=";
                                    cin>>k;
                                    h.modify(k);
                                    getch();
                                    break;
                                }
                            case 6:
                                {
                                    k=h.isempty();
                                    if(k==0)
                                        {
                                            cout<<"Empty Heap!!!";
                                            break;
                                        }
                                    cout<<"Enter element to delete=";
                                    cin>>k;
                                    h.del(k);
                                    getch();
                                    break;
                                }
                            case 7:
                                {
                                    h.display();
                                    getch();
                                    break;
                                }
                            case 8:
                                {
                                    h.convert();
                                    getch();
                                    break;
                                }
                            case 9:
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