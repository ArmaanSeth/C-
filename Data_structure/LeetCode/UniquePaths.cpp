#include<iostream>
#include<vector>
using namespace std;
class Solution 
    {
    public:
    int uniquePaths(int m, int n) 
        {
        if(m==1 || n==1)
            {
            return 1;
            }
        int dp[m][n];
        int r=m-1,c=n-1;
        for(int i=0;i<m;i++)
            {
            dp[i][c]=1;
            }
        for(int i=0;i<n;i++)
            {
            dp[r][i]=1;
            }
        r--;
        c--;
        while(r>=0)
            {
            for(int i=c;i>=0;i--)
                {
                dp[r][i]=dp[r+1][i]+dp[r][i+1];
                }
            r--;
            }
        return dp[0][0];
        }
    };
int main()
    {
    system("cls");
    Solution obj;
    int ans=obj.uniquePaths(3,7);
    cout<<"Ans="<<ans;
    return 0;
    }