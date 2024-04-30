#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int recursion(int n,vector<int> &dp)
        {
        if(n<0)
            {
            return 0;
            }
        if(n<3)
            {
            dp[n]=n;
            return n;
            }
        else
            {
            int k=0;
            for(int i=1;i<=n;i++)
                {
                int r=n-i,l=n-1-r,k1,k2;
                k1=recursion(r,dp);
                k2=recursion(l,dp);
                if(k1!=0 && k2!=0)
                    {
                    k+=k1*k2;
                    }
                else
                    k+=k1+k2;
                }
            dp[n]=k;
            }
        return dp[n];
        }
    int numTrees(int n) {
    vector<int> dp(n+1,0);
    return recursion(n,dp);        
    }
};
int main()
    {
    system("cls");
    Solution obj;
    cout<<obj.numTrees(3);
    return 0;
    }