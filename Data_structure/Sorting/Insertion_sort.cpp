#include<iostream>
using namespace std;
int insertion_sort(int arr[20],int n)
    {
        int temp,t,j,i;
        for(i=1;i<n;i++)
            {
                t=arr[i];
                for(j=i-1;j>=0;j--)
                    {
                        if(arr[j]>t)
                            {
                                arr[j+1]=arr[j];
                                temp=1;
                            }
                        else
                            {
                                break;
                            }
                    }
                if(temp==1)
                    {
                        arr[j+1]=t;
                    }
            }
        cout<<"\nSorted Array=";
        for(i=0;i<n;i++)
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
        insertion_sort(a,n);
        return 0;
    }