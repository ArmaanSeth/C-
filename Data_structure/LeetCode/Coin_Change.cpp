#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int recursion(vector<int>& coins, int amount,int pos,vector<vector<int>> &dp)
        {
        if(amount==0)
            {
            return 0;
            }
        else if(amount<0 || (pos>=coins.size() && amount>0))
            {
            return -1;
            }
        
        else    
            {
            int min=-1;
            for(int i=pos;i<coins.size();i++)
                {
                int a=0;
                if(dp[i][amount]!=-2)
                    {
                    a=dp[i][amount];
                    }
                else
                    {
                    a=recursion(coins,amount-coins[i],i,dp);
                    }
                if(min==-1)
                    {
                    min=a;
                    }
                if(a==-1)
                    {
                    dp[i][amount]=-1;
                    }
                if(min>=a && a!=-1)
                    {
                    dp[i][amount]=a;
                    min=a;
                    }
                }
            if(min==-1)
                return -1;
            return min+1;
            }
        }
    int coinChange(vector<int>& coins, int amount) {
    vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-2));
    return recursion(coins,amount,0,dp);
    }
};
int main()
    {
    system("cls");
    Solution obj;
    vector<int> coins={1,3,5};
    int ans=obj.coinChange(coins,8);
    cout<<"Ans="<<ans<<"\n ";
    return 0;
    }