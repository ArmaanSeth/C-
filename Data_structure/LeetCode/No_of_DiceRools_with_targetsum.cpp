#include<iostream>
#include<vector>
using namespace std;
class Solution 
    {  
    int mod = 1000000000+7;
    public:
    int recursion(int n,int k,int target,vector<vector<int>> &dp)
        {
        int ans=0;
        if(target==0)
            {
            return 0;
            }
        if(n==0)
            {
            if(target>k)
                return 0;
            else
                return 1;
            }
        else if(dp[n][target]!=-1)
            {
            return dp[n][target];
            }
        for(int i=1;i<=target;i++)
            {
            ans=(ans+recursion(n-1,k,target-i,dp))%mod;
    
            }
        return dp[n][target]=ans;
        }
    int numRollsToTarget(int n, int k, int target) 
        {
        vector<vector<int>> dp(n+1,vector<int>((target+1),-1));
        return recursion(n-1,k,target,dp);
        }
    };
int main()
    {
    system("cls");
    Solution obj;
    int ans=obj.numRollsToTarget(30,30,500);
    cout<<ans;
    return 0;
    }