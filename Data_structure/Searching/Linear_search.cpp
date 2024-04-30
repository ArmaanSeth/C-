#include<iostream>
using namespace std;
int linear_search(int arr[20],int b, int e)
    {
        bool t=false;
        for(int i=0;i<b;i++)
            {
                if(arr[i]==e)
                    {
                       t=true;
                       break; 
                    }
            }
        if(t)
            {
                cout<<"\nFound";
            }
        else
            {
                cout<<"\nNot Found";
            }
        return 0;
    }
int main()
    {
        system("cls");
        int a[20],i,s;
        cout<<"Enter no of element of array=";
        cin>>i;
        cout<<"Enter array=";
        for(int n=0;n<i;n++)
            {
                cin>>a[n];
            }
        cout<<"Enter element to be searched=";
        cin>>s;
        linear_search(a,i,s);
        return 0;
    }
