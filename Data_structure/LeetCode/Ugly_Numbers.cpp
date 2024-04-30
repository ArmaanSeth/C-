#include<iostream>
#include<vector>
using namespace std;
class Solution 
    {
    public:
    int nthUglyNumber(int n) 
        {
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(1);
        dp.push_back(2);
        dp.push_back(3);
        dp.push_back(4);
        dp.push_back(5);
        int k=3;//,c;
        if(n<6)
            {
            return dp[n];
            }
        for(int i=6;i<=n;i++)
            {
            if((i+1)%3!=0)
                {
                dp.push_back(2*dp[k]);
           //     c=dp[i];
                k++;
                }
            else
                {
                dp.push_back(3*dp[k-2]);
               // c=dp[i];
                }
            }
        return dp[n];
        }
    };
int main()
    {
    system("cls");
    Solution obj;
    int ans=obj.nthUglyNumber(10);
    cout<<"Ans="<<ans<<"\n ";
    return 0;
    }