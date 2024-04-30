#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int recursion(string s,int len,vector<int> &dp,int id)
        {
        if(s[id]=='0')
            {
            return 0;
            }
        if(id>len-1)
            {
            dp[id]=1;
            return 1;
            }
        if(dp[id]!=0)
            {
            return dp[id];
            }
        else    
            {
            int n=int(s[id])-48,m=int(s[id+1])-48;
            if(m==0)
                {
                if(n<3)
                    dp[id]+=recursion(s,len,dp,id+2);
                else
                    return 0;
                }
            else    
                {
                dp[id]+=recursion(s,len,dp,id+1);
                if(n*10+m<27)
                    {
                    dp[id]+=recursion(s,len,dp,id+2);
                    }
                }
            }
        return dp[id];
        }
    int numDecodings(string s) 
    {
    int n=s.length()-1;
    vector<int> dp(n+1,0);
    int k=recursion(s,n,dp,0); 
    if(k==0)
        return 0;
    for(int i=0;i<=n;i++)
        {
        if(dp[i]==0 && s[i]!='0')
            return 0;
        }
    return dp[0];
    }
};
int main()
    {
    system("cls");
    string s="12";
    Solution obj;
    cout<<obj.numDecodings(s);
    return 0;
    }