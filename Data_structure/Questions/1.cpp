#include<iostream>
#include<vector>
using namespace std;
int recursion(vector<int> A,vector<int> B, vector<int> C ,int p=0, int s=0,int c=0)
    {
    if(A[0]>p || B[0]>s)
        {
        return c+1;
        }
    else    
        {
        int a=0,b=0,max=0;
        int k=C[0];
        A.erase(A.begin());
        B.erase(B.begin());
        C.erase(C.begin());
        for(int i=0;i<=k;i++)
            {
            a=recursion(A,B,C,p+i,s+k-i,c+1);
            if(max<a)
                {
                max=a;
                }
            }
        return max;
        }
    }
int main()
    {
    system("cls");
    vector<int> a{1,2,4,9},b={1,2,4,9},c={2,1,2,3};
    cout<<recursion(a,b,c,1,1);
    return 0;
    }