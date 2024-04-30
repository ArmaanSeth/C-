 /*pivot as first element
#include<iostream>
using namespace std;
int partition(int arr[20],int first, int last)
    {
        int pivot,j=last,temp;
        pivot=arr[first];
        for(int i=last;i>first;i--)
            {
                if(arr[i]>pivot)
                    {
                    temp=arr[j];
                    arr[j]=arr[i];
                    arr[i]=temp;
                    j--;
                    }       
            }
        temp=arr[first];
        arr[first]=arr[j];
        arr[j]=temp;
        return j;
    }
int quick_sort(int arr[20],int first, int last)
    {
        int pos;
        if(first<last)
            {
            pos=partition(arr,first,last);            
            quick_sort(arr,pos+1,last);
            quick_sort(arr,first,pos-1);
            }
        return 0;
    }
int main()
    {
        system("cls");
        int a[20],n;
        cout<<"Enter no of element of array=";
        cin>>n;
        cout<<"Enter array=";
        for(int i=0;i<n;i++)
            {
                cin>>a[i];
            }
        quick_sort(a,0,n-1);
        cout<<"\nSorted Array=";
        for(int i=0;i<n;i++)
            {
                cout<<a[i]<<" ";
            }
        return 0;
    } */
//Pivot as last element
#include<iostream>
using namespace std;
int partition(int arr[20],int first, int last)
    {
        int pivot,j=first,temp;
        pivot=arr[last];
        for(int i=first;i<last;i++)
            {
                if(arr[i]<pivot)
                    {
                    temp=arr[j];
                    arr[j]=arr[i];
                    arr[i]=temp;
                    j++;
                    }       
            }
        temp=arr[last];
        arr[last]=arr[j];
        arr[j]=temp;
        return j;
    }
int quick_sort(int arr[20],int first, int last)
    {
        int pos;
        if(first<last)
            {
            pos=partition(arr,first,last);            
            quick_sort(arr,pos+1,last);
            quick_sort(arr,first,pos-1);
            }
        return 0;
    }
int main()
    {
        system("cls");
        int a[20],n;
        cout<<"Enter no of element of array=";
        cin>>n;
        cout<<"Enter array=";
        for(int i=0;i<n;i++)
            {
                cin>>a[i];
            }
        quick_sort(a,0,n-1);
        cout<<"\nSorted Array=";
        for(int i=0;i<n;i++)
            {
                cout<<a[i]<<" ";
            }
        return 0;
    }