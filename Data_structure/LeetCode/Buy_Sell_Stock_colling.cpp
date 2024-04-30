#include<iostream>
#include<vector>
using namespace std;
class Solution  
    {
    public:
    int recursion(vector<int> profits,int pos,int curr,vector<int>& dp)
        {
        if(pos>=profits.size())
            {
            return curr;
            }
        if(profits[pos]<0)
            {
            return recursion(profits,pos+1,curr,dp);
            }
        if(dp[pos]!=-1)
            {
            return (dp[pos]+curr);
            }
        if(pos==(profits.size()-1))
            {
            curr+=profits[pos];
            dp[pos]=profits[pos];
            return curr;
        if(profits[pos+1]<0)
            {
            curr=profits[pos];
            dp[pos]=recursion(profits,pos+2,curr,dp);
            return curr;
            }
        else
            {
            int a,b;
            a=recursion(profits,pos+2,curr+profits[pos],dp);
            b=recursion(profits,pos+3,curr+profits[pos+1],dp);
            dp[pos]=a;
            dp[pos+1]=b;
            if(a>b)
                {
                return a;
                }
            else
                {
                return b;
                }
            }
        }
    int maxProfit(vector<int> &prices) 
        {
        if(prices.size()<=1)
            {
            return 0;
            }
        vector<int> dp,dp2(prices.size()-1,-1);
        for(int i=1;i<prices.size();i++)
            {
            int max=-1;
            for(int j=0;j<i;j++)
                {
                if((prices[i]-prices[j])>max)
                    {
                    max=prices[i]-prices[j];
                    }
                }
            dp.push_back(max);
            }
        return recursion(dp,0,0,dp2);
        }
    };
int main()
    {
    system("cls");
    vector<int> prices={1,2,3,0,2};
    Solution obj;
    int ans=obj.maxProfit(prices);
    cout<<"Ans="<<ans;
    return 0;
    }