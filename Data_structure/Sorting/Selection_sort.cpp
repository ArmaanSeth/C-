#include<iostream>
using namespace std;
int smallest(int arr[20],int n,int j)
    {
        int small=arr[j],k;
        for(int i=j;i<n;i++)
            {
               if(arr[i]<small)
                {
                small=arr[i];    
                k=i;
                }
            }                
        return k;

    }
int selection_sort(int arr[20],int n)
    {
        int b[n],pos,temp;
        for(int i=0;i<n;i++)
            {
                pos=smallest(arr,n,i);
                b[i]=arr[pos];
                temp=arr[i];
                arr[i]=arr[pos];
                arr[pos]=temp;
            }
        cout<<"\nSorted Array=";
        for(int i=0;i<n;i++)
            {
                cout<<b[i]<<" ";
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
        selection_sort(a,n);
        return 0;
    }