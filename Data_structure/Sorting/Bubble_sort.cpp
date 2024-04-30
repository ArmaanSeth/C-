#include<iostream>
using namespace std;
int bubble_sort(int arr[20],int n)
    {
        int temp;
        for(int i=0;i<n;i++)
            {
            for(int j=0;j<n-1-i;j++)
                {
                if(arr[j]>arr[j+1])
                    {
                    temp=arr[j+1];
                    arr[j+1]=arr[j];
                    arr[j]=temp;
                    }
                }
            }
        cout<<"\nSorted Array=";
        for(int i=0;i<n;i++)
            {
                cout<<arr[i]<<" ";
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
        bubble_sort(a,n);
        return 0;
    }