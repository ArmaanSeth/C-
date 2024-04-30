#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
    if(s1.size()+s2.size()!=s3.size())
        return false;
    vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,0));
    dp[0][0]=1;
    for(int i=1;i<=s1.size();i++)
        {
        if(s1[i-1]==s3[i-1])
            {    
            if(dp[i-1][0]==1)
                dp[i][0]=1;
            }
        }
    for(int i=1;i<=s2.size();i++)
        {
        if(s2[i-1]==s3[i-1])
            {
            if(dp[0][i-1]==1)   
                dp[0][i]=1;
            }
        }    
    for(int i=1;i<=s1.size();i++)
        {
        for(int j=1;j<=s2.size();j++)
            {
            if(s3[i+j-1]==s1[i-1])
                {
                if(dp[i-1][j]==1)
                    dp[i][j]=1;
                }
            if(s3[i+j-1]==s2[j-1])
                {
                if(dp[i][j-1]==1)
                    dp[i][j]=1;
                }
            }
        }
    if(dp[s1.size()][s2.size()]==1)
        return true;
    return false;
    }
};
int main()
    {
    system("cls");
    Solution obj;
    string s1 = "db", s2 = "b", s3 = "cbb";
    bool ans=obj.isInterleave(s1,s2,s3);
    if(ans==true)
        cout<<"True";
    else
        cout<<"False";
    return 0;
    }