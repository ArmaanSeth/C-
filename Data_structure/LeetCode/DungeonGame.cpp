#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
        {
      //  vector<vector<vector<int>>> dp(dungeon.size(),vector<vector<int>>(2,vector<int>(dungeon[0].size(),0)));
        int dp[dungeon.size()][dungeon[0].size()][2];
        int r=dungeon.size()-1,c=dungeon[0].size()-1;
        if(dungeon[0][0]<0)
            {
            dp[0][0][0]=fabs(dungeon[0][0])+1;
            dp[0][0][1]=0;
            }
        else
            {
            dp[0][0][0]=1;
            dp[0][0][1]=dungeon[0][0];
            }
        for(int i=1;i<=r;i++)
            {
            if(dungeon[i][0]<0)
                {
                int k=dp[i-1][0][1];
                k=k+dungeon[i][0];
                if(k<0)
                    {
                    dp[i][0][0]=dp[i-1][0][0]-k;
                    dp[i][0][1]=0;
                    }
                else
                    {
                    dp[i][0][0]=dp[i-1][0][0];
                    dp[i][0][1]=k;
                    }
                }
            else
                {
                dp[i][0][0]=dp[i-1][0][0];
                dp[i][0][1]=dp[i-1][0][1]+dungeon[i][0];
                }
            }
        for(int i=1;i<=c;i++)
            {
            if(dungeon[0][i]<0)
                {
                int k=dp[0][i-1][1];
                k=k+dungeon[0][i];
                if(k<0)
                    {
                    dp[0][i][0]=dp[0][i-1][0]-k;
                    dp[0][i][1]=0;
                    }
                else
                    {
                    dp[0][i][0]=dp[0][i-1][0];
                    dp[0][i][0]=k;
                    }
                }
            else
                {
                dp[0][i][0]=dp[0][i-1][0];
                dp[0][i][1]=dp[0][i-1][1]+dungeon[0][i];
                }
            }
        int i=1;
        while(i<=r)
            {
            for(int j=1;j<=c;j++)
                {
                int a=dp[i-1][j][0],b=dp[i-1][j][1]; 
                if(a+b>dp[i][j-1][1]+dp[i][j-1][0])
                    {
                    a=dp[i][j-1][0];
                    b=dp[i][j-1][1];
                    }
                if(dungeon[i][j]<0)
                    {
                    int k=b+dungeon[i][j];
                    if(k<0)
                        {
                        dp[i][j][0]=a-k;
                        dp[i][j][1]=0;    
                        }
                    else
                        {
                        dp[i][j][0]=a;
                        dp[i][j][1]=k;
                        }
                    }
                else
                    {
                    dp[i][j][0]=a;
                    dp[i][j][1]=b+dungeon[i][j];
                    }
                }
            i++;
            } 
        return dp[r][c][0];    
        }
    };
int main()
    {
    system("cls");
    Solution obj;
    vector<vector<int>> k={{-2,-3,3},{-5,-10,1},{10,30,-5}};
    int ans=obj.calculateMinimumHP(k);
    cout<<"Ans="<<ans;
    return 0;
    }