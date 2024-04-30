#include<iostream>
#include<math.h>
using namespace std;
class Solution 
{
public:
int rec(int f,int l,int k,int c)
    {
    if(f==l)
        {
        return f;
        }
    
    if(c%2==1)
        {
        l-=pow(2,k);
        f+=pow(2,k);
        return rec(f,l,k+1,c/2);
        }
    if(k%2==1)
        {
        l-=pow(2,k);
        return rec(f,l,k+1,c/2);
        }
    f+=pow(2,k);
    return rec(f,l,k+1,c/2);
    }
int lastRemaining(int n) 
    {
    if(n==1)
        {
        return 1;
        }
    if(n%2==1)
        {
        return rec(2,n-1,1,n/2);
        }
    return rec(2,n,1,n/2);
    }
};
int main()
    {
    system("cls");
    Solution obj;
    int i=obj.lastRemaining(50);
    cout<<i;
    return 0;
    }