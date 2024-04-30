#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int recursion(vector<int> s,int n,int count,vector<int> &dp)
        {
        if(n==0)
            {
            return count;
            }
        if(n<0)
            {
            return -1;
            }
        if(dp[n]==-1)
            return -1;
        if(dp[n]>0)
            {
            return count+dp[n];
            }
        else
            {
            int min=-1,a,i=0,k=0;
            while(i<s.size() && s[i]<=n)
                {
                k=s[i];
                i++;
                }
            i--;
            for(i=i;i>=0;i--)
                {
                a=recursion(s,n-s[i],count+1,dp);
                if(a==-1)
                    {
                    continue;
                    }
                if(min==-1)
                    {
                    min=a;
                    }
                else
                    {
                    if(min>a)
                        {
                        min=a;
                        }
                    }
                }
            dp[n]=min-count;
            return min;
            }
        }
    int numSquares(int n) 
    {
    vector<int> s;
    int i=1;
    while(i*i<=n)
        {
        s.push_back(i*i);
        i++;
        } 
    vector<int> dp(n+1,-2);
    return recursion(s,n,0,dp);
    }
};
int main()
    {
    system("cls");
    Solution obj;
    int ans=obj.numSquares(48);
    cout<<"Ans="<<ans<<"\n ";
    return 0;
    }