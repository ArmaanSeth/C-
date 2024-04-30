#include<iostream>
#include<vector>
using namespace std;
class Solution 
    {
    public:
    int minPathSum(vector<vector<int>>& grid) 
        {
        int dp[grid.size()][grid[0].size()];
        int r=grid.size()-1,c=grid[0].size()-1;
        dp[r][c]=grid[r][c];
        for(int i=r-1;i>=0;i--)
            {
            dp[i][c]=grid[i][c]+dp[i+1][c];
            }
        for(int i=c-1;i>=0;i--)
            {
            dp[r][i]=grid[r][i]+dp[r][i+1];
            }
        r--;
        c--;
        while(r>=0)
            {
            for(int i=c;i>=0;i--)
                {
                int min=dp[r][i+1];
                if(min>dp[r+1][i])
                    {
                    min=grid[r+1][i];
                    }
                dp[r][i]=min+grid[r][i];
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
    vector<vector<int>> k={{1,3,1},{1,5,1},{4,2,1}};
    int ans=obj.minPathSum(k);
    cout<<"Ans="<<ans;
    return 0;
    }