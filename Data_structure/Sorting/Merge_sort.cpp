#include<iostream>
using namespace std;
int merge(int arr[20],int first,int mid,int last)
    {
        int l1,l2,temp,i,j,h=first;
        l1=mid-first+1;
        l2=last-mid;
        int a[l1],b[l2];
        for(i=0;i<l1;i++)
            {
                a[i]=arr[i+first];
                cout<<a[i]<<" ";
            }
        for(i=0;i<l2;i++)
            {
                b[i]=arr[i+mid+1];
                cout<<b[i]<<" ";
            }
        i=0;
        j=0;
        while(i<l1 && j<l2)
            {
                if(a[i]<b[j])
                    {
                    arr[h]=a[i];
                    i++;
                    }
                else    
                    {
                    arr[h]=b[j];
                    j++;
                    }
                h++;
            }
        while(i<l1)
            {
                arr[h]=a[i];
                i++;
                h++;
            }
        while(j<l1)
            {
                arr[h]=b[j];
                h++;
                j++;
            }
        return 0;
    }
int merge_sort(int arr[20],int first, int last)
    {
        int mid;
        if(first<last)
            {
            mid=first+(last-first)/2;
            merge_sort(arr,first,mid);
            merge_sort(arr,mid+1,last);
            merge(arr,first,mid,last);
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
        merge_sort(a,0,n-1);
        cout<<"\nSorted Array=";
        for(int i=0;i<n;i++)
            {
                cout<<a[i]<<" ";
            }
        return 0;
    }