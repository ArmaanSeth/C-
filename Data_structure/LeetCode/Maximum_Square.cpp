#include<iostream>
#include<vector>
using namespace std;
class Solution 
    {
    public:
    int maximalSquare(vector<vector<char>>& matrix) 
        {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));
        int r=matrix.size(),c=matrix[0].size(),max=0;
        for(int i=0;i<r;i++)
            {
            if(matrix[i][0]=='1')
                max=1;
            dp[i][0]=matrix[i][0]-'0';
            }
        for(int i=0;i<c;i++)
            {
            if(matrix[0][i]=='1')
                max=1;
            dp[0][i]=matrix[0][i]-'0';
            }
        int i=1;
        while(i<r)
            {
            for(int j=1;j<c;j++)
                {
                if(matrix[i][j]=='1')
                    {
                    int a=dp[i-1][j];
                    if(a>dp[i][j-1])
                        a=dp[i][j-1];
                    if(a>dp[i-1][j-1])
                        a=dp[i-1][j-1];
                    dp[i][j]=a+1;
                    if(max<dp[i][j])
                        {
                        max=dp[i][j];
                        }
                    }
                }
            i++;
            }
        return max*max;
        }
    };
int main()
    {
    system("cls");
    vector<vector<char>> matrix={{'1','0','1','0'},{'1','0','1','1'},{'1','0','1','1'},{'1','1','1','1'}};
    Solution obj;
    int ans=obj.maximalSquare(matrix);
    cout<<"Ans="<<ans<<endl<<" ";
    return 0;
    }