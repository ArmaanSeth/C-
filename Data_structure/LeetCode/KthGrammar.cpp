#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
class Solution 
    {
    public:
    int recursion(int n, int k, int f)
        {
        int i=0,j=0;
        if((k==1 && f==1) || (k==2 && f==-1))
            {
            return 0;
            }
        else if(k==2 || k==1)
            {
            return 1;
            }
        if(k>pow(2,n-2))
            {
            k=k-pow(2,n-2);
            n--;
            return recursion(n,k,f*-1);
            }
        else
            {
            n--;
            return recursion(n,k,f);
            }
        }
    int kthGrammar(int n, int k) 
        {
        return recursion(n,k,1);
        }
    };
int main()
    {
    system("cls");
    Solution obj;
    int k=obj.kthGrammar(16,8);
    cout<<k;
    return 0;
    }