#include<iostream>
#include<conio.h>
#include<vector>
#include<string.h>
#include<map>
using namespace std;
class Solution {
public:
    int rec(int x,int ans, int n, int t)
        {
        if(t==n)
            {
            return ans;
            }
        if((2*t)<n)
            {
            ans*=ans;
            t*=2;
            return rec(x,ans,n,t);
            }
        if(t<n)
            {
            ans*=x;
            t++;
            }
        return rec(x,ans,n,t);
        }
    double rec1(double x,long double ans, int s, int t)
        {
        if(t==s)
            {
            return ans;
            }
        if(2*t>=s)
            {
            ans*=ans;
            t*=2;
            return rec1(x,ans,s,t);
            }
        if(t>s)
            {
            ans/=x;
            t--;
            }
        return rec1(x,ans,s,t);
        }
    double myPow(double x, double n) 
    {
    int i=n;
    if(n==0 || x==1)
        {
        return 1;
        }
    if(n<0)
        {   
        return rec1(x,(1/x),n,-1);
        }
    return rec(x,x,n,1);
    }
};
int main()
    {
        system("cls");
        Solution obj;
        
        int i=obj.myPow(2.00000,-2147483648);
        cout<<i;
        getch();
        return 0;
    }