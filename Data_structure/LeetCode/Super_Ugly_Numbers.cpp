#include<iostream>
#include<vector>
using namespace std;
class Solution 
    {
    public:
    int nthSuperUglyNumber(int n, vector<int>& primes) 
        {
        if(n==1)
            {
            return 1;
            }
        vector<long> m(primes.size(),0),dp(n,1);
        for(int i=1;i<n;i++)
            {
            int min=INT32_MAX,id=0;//primes[0]*dp[m[0]],id=0;
            for(int j=0;j<primes.size();j++)
                {
                if(dp[i-1]>=primes[j]*dp[m[j]])
                    {
                    m[j]++;
                    }
                if(primes[j]*dp[m[j]]<min)
                    {
                    min=primes[j]*dp[m[j]];
                    id=j;
                    }
                }
            m[id]+=1;
            dp[i]=min;
            }
        return dp[n-1];
        }   
    };
int main()
    {
    system("cls");
    Solution obj;
    vector<int> primes={2,7,13,19};
    int ans =obj.nthSuperUglyNumber(12,primes);
    cout<<"Ans="<<ans<<"\n ";
    return 0;
    }