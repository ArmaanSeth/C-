#include<iostream>
using namespace std;
int binary_search(int arr[20],int first,int last,int e)
    {
    int middle;
    bool t=false;
    while(first<last)
        {
            
            middle=(last+first)/2;
            if(arr[middle]>e)
                {
                    last=middle-1;
                }
            else if(arr[middle]==e)
                {
                    t=true;
                    break;
                }
            else
                {
                    first=middle+1;
                }
        }
    if(t==true)
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
        int a[20],l,s,f=0;
        cout<<"Enter no of element of array=";
        cin>>l;
        cout<<"Enter array=";
        for(int i=0;i<l;i++)
            {
                cin>>a[i];
            }
        cout<<"Enter element to be searched=";
        cin>>s;
        binary_search(a,f,l-1,s);
        return 0;
    }