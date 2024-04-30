#include<iostream>
#include<math.h>
#include<map>
using namespace  std;
class Solution 
    {
    public:
    int length(int n)
        {
        map<int,int> m;
        m[1]=1;
        for(int i=2;i<=n;i++)
            {
            m[i]=2*m[i-1]+1;
            }
        return m[n];
        }
    char recursion(int n,int k,int f)
        {
        if(n<3)
            {
            if((k==1 && f==1) || (k!=1 && f==-1))
                {
                return '0';
                }
            else
                {
                return '1';
                }
            }
        int total_digits=length(n);
        if((k-1)==(total_digits/2))
            {
            if(f==1)
                return '1';
            else
                return '0';
            }
        else if((k-1)>(total_digits/2))
            {
            return recursion(n-1,(total_digits/2-((k-1)-(total_digits/2))+1),-1*f);
            }
        else    
            {
            return recursion(n-1,k,f);
            }
        }
    char findKthBit(int n, int k) 
        {
        return recursion(n,k,1);
        }
    };
int main()
    {
    system("cls");
    Solution obj;
    char c=obj.findKthBit(4,12);
    cout<<c;
    return 0;
    }