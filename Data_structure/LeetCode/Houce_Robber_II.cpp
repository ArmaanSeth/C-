#include<iostream>
#include<vector>
using namespace std;
class Solution 
    {
    public:
    int recursion(vector<int>& nums, int pos, vector<vector<int>> &dp,int first)
        {
        if(pos>=nums.size())
            return 0;
        if(pos==(nums.size()-1) && first==1)
            return 0;
        if(dp[pos][first]!=-1)
            {
            if(pos==(nums.size()-1))
                return dp[pos][first];
            else if(dp[pos+1][first]!=-1)
                {
                if(dp[pos]>dp[pos+1])
                    return dp[pos][first];
                else
                    return dp[pos+1][first];
                }
            }
        int a=nums[pos],b,c;
        if(pos+1<nums.size())
            b=nums[pos+1];
        else
            return a;
        if(pos==0)
            a+=recursion(nums,pos+2,dp,1);
        else
            a+=recursion(nums,pos+2,dp,first);
        if(pos+1==nums.size()-1 && first==1)
            return a;
        b+=recursion(nums,pos+3,dp,first);
        if(pos+2<nums.size())
            {
            if(pos+2==nums.size()-1 && first==1)
                c=-1;
            else
                c=nums[pos+2];
            }
            
        else
            {
            dp[pos][first]=a;
            if(pos+1<nums.size())
                dp[pos+1][first]=b;
            if(pos+2<nums.size())
                dp[pos+2][first]=c;
            if(b>a)
                return b;
            else
                return a;
            }        
        c+=recursion(nums,pos+4,dp,first);
        dp[pos][first]=a;
        if(pos+1<nums.size())
            dp[pos+1][first]=b;
        if(pos+2<nums.size()-1)
            dp[pos+2][first]=c;
        if(b>=a && b>=c)
            return b;
        else if(c>=a && c>=b)
            return c;
        else
            return a;                
        }
    int rob(vector<int>& nums) 
        {
        if(nums.size()==1)
            return nums[0];
        vector<vector<int>> dp(nums.size(),vector<int>(2,-1));
        return recursion(nums,0,dp,0);
        }
    };
int main()
    {
    system("cls");
    vector<int> k={1,1,3,6,7,10,7,1,8,5,9,1,4,4,3};
    Solution obj;
    int a=obj.rob(k);
    cout<<"ans="<<a;
    return 0;
    }