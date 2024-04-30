#include<iostream>
#include<vector>
using namespace std;
class Solution 
    {
    public:
    int recursion(vector<int>& nums, int pos, vector<int> &dp)
        {
        if(pos>=nums.size())
            return 0;
        if(dp[pos]!=-1)
            {
            if(pos==(nums.size()-1))
                return dp[pos];
            else if(dp[pos+1]!=-1)
                {
                if(dp[pos]>dp[pos+1])
                    return dp[pos];
                else
                    return dp[pos+1];
                }
            }
        int a=nums[pos],b;
        if(pos+1<nums.size())
            b=nums[pos+1];
        else
            return a;
        a+=recursion(nums,pos+2,dp);
        b+=recursion(nums,pos+3,dp);
        dp[pos]=a;
        if(pos+1<nums.size())
            dp[pos+1]=b;
        if(b>a)
            return b;
        else
            return a;                
        }
    int rob(vector<int>& nums) 
        {
        if(nums.size()==1)
            return nums[0];
        vector<int> dp(nums.size(),-1);
        return recursion(nums,0,dp);
        }
    };
int main()
    {
    system("cls");
    vector<int> k={1,3,1,3,100};
    Solution obj;
    int a=obj.rob(k);
    cout<<"ans="<<a;
    return 0;
    }