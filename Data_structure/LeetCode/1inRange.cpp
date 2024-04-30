#include<iostream>
#include<math.h>
using namespace std;
class Solution {
public:
int rec(int n)
    {
    if(n<1)
        {
        return 0;
        }
    if(n<10)
        {
        return 1;
        }
    int i=log10(n),k=pow(10,i),s=0;
    s=i*pow(10,i-1);
    k=n/k;
    s*=k;
    if(k!=1)
        {
        s+=pow(10,i)-1;
        }
    s++;
    if(n/((int)pow(10,i))==1)
        {
        s+=n%((int)pow(10,i));
        }
    n=n%((int)pow(10,i));
    s+=rec(n);
    return s;    
    }
int countDigitOne(int n) 
    {
    return rec(n);
    }
};
int main()
    {
    system("cls");
    Solution obj;
    int i=obj.countDigitOne(30);
    cout<<i;
    return 0;
    }